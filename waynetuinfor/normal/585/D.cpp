#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 25, inf = 1e9;
int l[3][maxn], k;
long long p[maxn];
vector<int> scf[2000000], scb[2000000];

namespace std {
    template <> struct hash<pair<int, int>> {
        long long operator()(const pair<int, int> &p) const {
            return p.first * 1ll * inf + p.second;
        }
    };
}

unordered_map<pair<int, int>, pair<int, int>> mp;
// map<pair<int, int>, pair<int, int>> mp;
// gp_hash_table<pair<int, int>, pair<int, int>> mp;

void dfsf(int now, int stop, int s, vector<int> &tsc) {
    if (now == stop) {
        scf[s] = vector<int>(tsc.begin(), tsc.end());
        return;
    }
    for (int i = 0; i < 3; ++i) tsc[i] += l[i][now];
    for (int i = 0; i < 3; ++i) {
        tsc[i] -= l[i][now];
        dfsf(now + 1, stop, s + p[now] * i, tsc);
        tsc[i] += l[i][now];
    }
    for (int i = 0; i < 3; ++i) tsc[i] -= l[i][now];
}

void dfsb(int now, int stop, int s, vector<int> &tsc) {
    if (now == stop) {
        scb[s] = vector<int>(tsc.begin(), tsc.end());
        return;
    }
    for (int i = 0; i < 3; ++i) tsc[i] += l[i][now];
    for (int i = 0; i < 3; ++i) {
        tsc[i] -= l[i][now];
        dfsb(now + 1, stop, s + p[now - k] * i, tsc);
        tsc[i] += l[i][now];
    }
    for (int i = 0; i < 3; ++i) tsc[i] -= l[i][now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) cin >> l[j][i];
    p[0] = 1ll;
    for (int i = 1; i < maxn; ++i) p[i] = p[i - 1] * 3ll;
    k = n / 2;
    vector<int> t(3, 0);
    dfsf(0, k, 0, t); dfsb(k, n, 0, t);
    for (int s = 0; s < p[k]; ++s) {
        vector<int> sc = scf[s];
        if (mp.find(make_pair(sc[0] - sc[1], sc[1] - sc[2])) == mp.end()) mp[make_pair(sc[0] - sc[1], sc[1] - sc[2])] = make_pair(sc[0], s);
        else if (sc[0] > mp[make_pair(sc[0] - sc[1], sc[1] - sc[2])].first) mp[make_pair(sc[0] - sc[1], sc[1] - sc[2])] = make_pair(sc[0], s);
    }
    int ans = -inf, bstf = -1, bstb = -1;
    for (int s = 0; s < p[n - k]; ++s) {
        vector<int> sc = scb[s]; 
        if (mp.find(make_pair(sc[1] - sc[0], sc[2] - sc[1])) == mp.end()) continue;
        auto p = mp[make_pair(sc[1] - sc[0], sc[2] - sc[1])];
        if (sc[0] + p.first > ans) {
            ans = sc[0] + p.first;
            bstf = p.second;
            bstb = s;
        }
    }
    if (ans == -inf) return cout << "Impossible" << endl, 0;
    for (int i = 0; i < k; ++i) {
        int rem = bstf % 3;
        if (rem == 0) cout << "MW" << endl;
        if (rem == 1) cout << "LW" << endl;
        if (rem == 2) cout << "LM" << endl;
        bstf /= 3;
    }
    for (int i = k; i < n; ++i) {
        int rem = bstb % 3;
        if (rem == 0) cout << "MW" << endl;
        if (rem == 1) cout << "LW" << endl;
        if (rem == 2) cout << "LM" << endl;
        bstb /= 3;
    }
}