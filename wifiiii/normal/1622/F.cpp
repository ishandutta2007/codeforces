#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 6;
int prime[maxn], np[maxn], mp[maxn], tot = 0;

void init(int n) {
    np[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(!np[i]) prime[++tot] = i, mp[i] = i;
        for(int j = 1; j <= tot; ++j) {
            if(i * prime[j] > n) break;
            np[i * prime[j]] = 1;
            mp[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
vector<int> solve(int n) {
    vector<unsigned long long> magic(n + 1);
    for(int i = 2; i <= n; ++i) {
        if(!np[i]) magic[i] = mrand();
        else magic[i] = magic[i / mp[i]] ^ magic[mp[i]];
    }
    vector<unsigned long long> a(n + 1);
    for(int i = 2; i <= n; ++i) {
        a[i] = a[i - 1] ^ magic[i];
    }
    unsigned long long s = 0;
    for(int i = 2; i <= n; ++i) s ^= a[i];
    for(int i = 0; i <= n; ++i) {
        if(s == a[i]) {
            vector<int> ret;
            for(int j = 1; j <= n; ++j) {
                if(i != j) ret.push_back(j);
            }
            return ret;
        }
    }
    vector<pair<unsigned long long, int>> ps;
    for(int i = 2; i <= n; ++i) {
        ps.push_back({a[i], i});
    }
    sort(ps.begin(), ps.end());
    for(int i = 2; i <= n; ++i) {
        unsigned long long target = s ^ a[i];
        auto it = lower_bound(ps.begin(), ps.end(), make_pair(target, -1));
        if(it != ps.end()) {
            if(it->first == target && it->second != i) {
                vector<int> ret;
                for(int j = 1; j <= n; ++j) {
                    if(i != j && it->second != j) ret.push_back(j);
                }
                return ret;
            }
            if(next(it) != ps.end() && next(it)->first == target) {
                vector<int> ret;
                for(int j = 1; j <= n; ++j) {
                    if(i != j && next(it)->second != j) ret.push_back(j);
                }
                return ret;
            }
        }
    }
    return solve(n - 1);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    init(n);
    auto ans = solve(n);
    cout << ans.size() << '\n';
    for(int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
}