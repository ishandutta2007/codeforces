#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int seed;
int R(int mod) {
    int ret = seed;
    seed = (seed * 7ll + 13) % 1000000007;
    return ret%mod+1;
}

map<int, int> S; // l, r
long long V[100001];

int n, m, vmax;

void split(int x) {
    if(x == 0 || x == n+1) return;
    auto it = S.lower_bound(x);
    if(it->first == x) return;
    it--;
    int r = it->second;
    it->second = x-1;
    S.emplace(x, r);
    V[x] = V[it->first];
}

long long pow(long long x, int p, long long mod) {
    if(p == 0) return 1%mod;
    if(p == 1) return x%mod;
    long long re = pow(x, p/2, mod);
    re = re * re % mod;
    if(p&1)
        return re * x % mod;
    return re;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &seed, &vmax);
    for(int i=1; i<=n; i++) {
        S.emplace(i, i);
        V[i] = R(vmax);
    }
    for(int q=0; q<m; q++) {
        int op, l, r, x, y;
        op = R(4); l = R(n); r = R(n);
        if(l > r) l^=r^=l^=r;
        if(op == 3) x = R(r-l+1);
        else x = R(vmax);

        if(op == 4) y = R(vmax);
        split(l);
        split(r+1);
        if(op == 1) {
            for(auto it = S.lower_bound(l); it != S.end() && it->second<=r; it++)
                V[it->first] += x;
        }
        else if(op == 2) {
            for(auto it = S.lower_bound(l); it != S.end() && it->second<=r;)
                it = S.erase(it);
            S.emplace(l, r);
            V[l] = x;
        }
        else if(op == 3) {
            vector<pair<long long, int>> U;
            for(auto it = S.lower_bound(l); it != S.end() && it->second<=r; it++)
                U.emplace_back(V[it->first], it->second - it->first + 1);
            sort(U.begin(), U.end());
            for(auto [v, c]: U) {
                if((x -= c) <= 0) {
                    printf("%lld\n", v);
                    break;
                }
            }
        }
        else if(op == 4) {
            long long ans = 0;
            for(auto it = S.lower_bound(l); it != S.end() && it->second<=r; it++)
                ans = (ans + pow(V[it->first]%y, x, y) * (it->second - it->first + 1) % y) % y;
            printf("%lld\n", ans);
        }

    }
    return 0;
}