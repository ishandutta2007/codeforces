#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int w[N];
unordered_map <int, vector <pair <int, int>>> ff;

vector <pair <int, int>> fact(int n) {
    if (ff.find(n) != ff.end())
        return ff[n];

    int nn = n;
    vector <pair <int, int>> res;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            res.push_back({i, 1});
            while (n % i == 0) {
                n /= i;
                res.back().second *= i;
            }
        }
        i++;
    }
    if (n != 1)
        res.push_back({n, n});
    ff[nn] = res;
    return res;
}

int bpow(int a, int n, int m) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a % m;
    if (n % 2 == 0) {
        int mem = bpow(a, n / 2, m);
        return (mem * mem) % m;
    }
    return (bpow(a, n - 1, m) * a) % m;
}

int ans_or_max(int l, int r) {
    vector <int> kek;
    for (int i = l; i < l + 4 && i <= r && w[i] != 1; i++) {
        kek.push_back(w[i]);
    }
    int res = 1;
    for (int i = (int) kek.size() - 1; i >= 0; i--) {
        int c = kek[i];
        if (c >= 30)
            return -1;
        int nres = 1;
        for (int t = 0; t < res; t++) {
            nres = nres * c;
            if (nres >= 30)
                return -1;
        }
        res = nres;
    }
    return res;
}

vector <vector <int>> mods;

void test(int n) {
    set <int> s_mods;
    s_mods.insert(n);
    while (!s_mods.empty()) {
        set <int> nmods;
        mods.push_back({});
        for (int m : s_mods) {
            mods.back().push_back(m);
            auto f = fact(m);
            for (auto [p, pk] : f) {
                nmods.insert(pk - pk / p);
            }
        }
        s_mods = nmods;
    }
}

int who(int m, vector <int> results) {
    auto f = fact(m);
    assert(f.size() == results.size());
    int p1 = f[0].second;
    int phi1 = f[0].second - f[0].second / f[0].first;
    int a1 = results[0];

    for (int i = 1; i < (int) f.size(); i++) {
        int a2 = results[i];
        int p2 = f[i].second;
        int phi2 = f[i].second - f[i].second / f[i].first;
        int p = p1 * p2;
        int s1 = (((p1 * bpow(p1, phi2 - 1, p2)) % p) * a2) % p;
        int s2 = (((p2 * bpow(p2, phi1 - 1, p1)) % p) * a1) % p;
        a1 = (s1 + s2) % p;
        phi1 = phi1 * phi2;
        p1 = p;
    }
    assert(p1 == m);
    return a1;
}

int solve(int l, int r) {
    vector <vector <int>> ans(mods.size());
    for (int t = min(r - l, (int) mods.size() - 1); t >= 0; t--) {
        for (int m : mods[t]) {
            if (m == 1) {
                ans[t].push_back(0);
                continue;
            }
            if (l + t == r) {
                ans[t].push_back(w[r] % m);
                continue;
            }
            int a = w[l + t];
            vector <int> results;
            for (auto [p, pk] : fact(m)) {
                if (a % p == 0) {
                    int c = ans_or_max(l + t + 1, r);
                    if (c == -1) {
                        results.push_back(0);
                        continue;
                    }
                    int val = 1;
                    for (int t = 0; t < c; t++) {
                        val = (val * a) % pk;
                        if (val == 0)
                            break;
                    }
                    results.push_back(val);
                    continue;
                }
                int kek = pk - pk / p;
                int pw = -1;
                for (int z = 0; z < (int) mods[t + 1].size(); z++) {
                    if (mods[t + 1][z] == kek) {
                        pw = ans[t + 1][z];
                        break;
                    }
                }
                assert(pw != -1);
                results.push_back(bpow(a, pw, pk));
            }
            ans[t].push_back(who(m, results));
        }
    }
    return ans[0][0];
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    test(m);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << "\n";
    }
}