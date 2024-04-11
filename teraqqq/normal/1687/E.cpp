#include <bits/stdc++.h>

using namespace std;

vector<pair<int, vector<int>>> ans;
vector<int> tmp;
int ans_sz = 0;

void write_lcm(vector<int> v, int t) {
    sort(v.begin(), v.end());
    if (!v.empty() && t != 0) ans.emplace_back(t, v), ans_sz += abs(t);
}

void write_gcd(const vector<int>& v, int t, int pos = 0) {
    if (pos == 0) t = -t;

    if (v.size() == pos) {
        write_lcm(tmp, t);
    } else {
        write_gcd(v, +t, pos + 1);
        tmp.push_back(v[pos]);
        write_gcd(v, -t, pos + 1);
        tmp.pop_back();
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    mt19937 rng(1337228);
    shuffle(p.begin(), p.end(), rng);

    vector<int> v;
    int g = 0;
    for (int i : p) {
        if (gcd(g, a[i]) != g) {
            g = gcd(g, a[i]);
            v.push_back(i);
        }
    }

    const int m = v.size();
    write_gcd(v, -m+2);

    for (int i : v) {
        vector<int> u;
        int g = 0;
        for (int j : p) {
            if (j == i) continue;
            if (gcd(g, a[j]) != g) {
                g = gcd(g, a[j]);
                u.push_back(j);
            }
        }

        write_gcd(u, 1);
    }

    cout << ans_sz << '\n';
    for (auto [pw, v] : ans) {
        for (int i = 0; i < +pw; ++i) {
            cout << 0 << ' ' << v.size();
            for (int x : v) cout << ' ' << x+1;
            cout << '\n';
        }

        for (int i = 0; i < -pw; ++i) {
            cout << 1 << ' ' << v.size();
            for (int x : v) cout << ' ' << x+1;
            cout << '\n';
        }
    }
}