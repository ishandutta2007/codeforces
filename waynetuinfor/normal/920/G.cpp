#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const long long inf = 1e18;
int md[maxn];
bool v[maxn];
vector<int> pr;

bool check(long long t, int x, int p, int k, const vector<int> &dv) {
    long long s = 0;
    for (int i = 1; i < (1 << dv.size()); ++i) {
        int d = 1;
        for (int j = 0; j < dv.size(); ++j) if (i >> j & 1) d *= dv[j];
        // printf("d = %d\n", d);
        if (__builtin_popcount(i) & 1) s += t / d - x / d;
        else s -= t / d - x / d;
    }  
    // printf("check t = %lld s = %lld\n", t, s);
    return (t - x) - s >= k;
}    

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), md[i] = i;
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            md[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

int main() {
    sieve();
    int t; scanf("%d", &t);
    while (t--) {
        int x, p, k; scanf("%d %d %d", &x, &p, &k);
        vector<int> dv;
        long long t = p;
        while (t > 1) {
            int d = md[t];
            dv.push_back(d);
            while (t % d == 0) t /= d;
        }
        sort(dv.begin(), dv.end()); dv.resize(unique(dv.begin(), dv.end()) - dv.begin());
        int d = 60; long long ans = inf;
        while (d--) {
            if (ans - (1ll << d) > x) if (check(ans - (1ll << d), x, p, k, dv)) ans -= (1ll << d);
        }
        printf("%lld\n", ans);
    }
    return 0;
}