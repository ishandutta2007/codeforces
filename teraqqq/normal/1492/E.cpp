#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;

const int M = 250000;

bool check(int n, int m, const vi& res, const vector<vi>& v) {
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (res[j] != v[i][j]) ++cnt;
        }
        if (cnt > 2) return false;
    }

    return true;
}

optional<vi> solve() {
    int n, m; cin >> n >> m;
    vector v(n, vi(m));
    vi res(m);
    for (vi& u : v) for(int& x : u) cin >> x;
    for (int i = 0; i < m; ++i) {
        map<int, int> cnt;
        for (int j = 0; j < n; ++j)
            cnt[v[j][i]]++;
        int maxCount = 0;
        for (auto [a, b] : cnt) maxCount = max(maxCount, b);
        int moda = -1;
        for (auto [a, b] : cnt) if (b == maxCount) moda = a;
        res[i] = moda;
    }

    vector<vi> errs;
    map<pair<int, int>, int> deg;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        vi er;
        for (int j = 0; j < m; ++j) {
            if (res[j] != v[i][j]) ++cnt, er.push_back(j);
        }
        if (cnt > 4) return nullopt;

        if (cnt == 4) {
            for (int u : er)
            for (int t : er) {
                if (u <= t) continue;
                auto newRes = res;
                newRes[u] = v[i][u];
                newRes[t] = v[i][t];
                if (check(n, m, newRes, v)) return newRes;
            }

            return nullopt;
        }

        if (cnt == 3) {
            errs.push_back(er);
            for (int x : er) deg[{x, v[i][x]}]++;
        }
    }

    if (errs.empty()) return res;

    vector<pair<int, int>> mustHave;
    const int k = errs.size();
    for (auto [e, d] : deg) {
        if (2*d >= k) mustHave.push_back(e);
    }
    
    if (mustHave.empty()) return nullopt;

    for (auto [ni, nx] : mustHave) {
        auto newRes = res;
        newRes[ni] = nx;

        map<pair<int, int>, int> d2;

        int kk = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            vi er;
            for (int j = 0; j < m; ++j) {
                if (res[j] != v[i][j]) ++cnt, er.push_back(j);
            }
            if (cnt > 3) return nullopt;

            if (cnt == 3) {
                for (int j : er) d2[{j,v[i][j]}]++;
                ++kk;
            }
        }

        if (!kk) return newRes;

        for (auto [ch, x] : d2) {
            if (x != kk) continue;
            auto newRes2 = newRes;
            newRes2[ch.first] = ch.second;
            if (check(n, m, newRes2, v)) return newRes2;
        }
    }

    return nullopt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto res = solve();
    if (res.has_value()) {
        cout << "Yes" << endl;
        for (int x:  res.value()) cout  << x << ' ';
        cout << endl;
    } else {
        cout << "No" << endl;
    }
}