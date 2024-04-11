// 429D
// funzione strana

#include <bits/stdc++.h>
using namespace std;

#define INF 1e17

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, d, r;
vector<pair<long long, long long>> p, cp;
set<pair<long long, long long>> s;
pair<long long, long long> x;

long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

pair<long long, long long> sw(pair<long long, long long> a) {
    long long f, s;
    f = a.first;
    s = a.second;
    return {s, f};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        p.push_back({i + 1, a});
    }
    for (i = 1; i < n; i++) {
        p[i].second += p[i - 1].second;
    }

    sort(p.begin(), p.end());

    /* for (auto u : p) {
        cout << u.first << ' ' << u.second << endl;
    } */

    d = INF;
    r = 0;
    for (i = 0; i < n; i++) {
        s.insert(sw(p[i]));
        // cout << sw(p[i]).first << ' ' << sw(p[i]).second << endl;
        if (i > 0) {
            d = min(d, dist(p[i - 1], p[i]));
        }
        // cout << d << endl;

        while (p[i].first - p[r].first > sqrt(d) + 1) {
            s.erase(sw(p[r]));
            // cout << "erase " << sw(p[r]).first << ' ' << sw(p[r]).second << endl;
            r++;
            // cout << "r = " << r << endl;
        }

        cp.clear();
        // cout << p[i].second - sqrt(d) - 1 << ' ' << p[i].second + sqrt(d) + 1 << endl;
        copy(s.lower_bound({p[i].second - sqrt(d) - 1, -INF}), s.upper_bound({p[i].second + sqrt(d) + 1, -INF}), back_inserter(cp));
        // cout << "copy" << endl;
        for (auto u : cp) {
            // cout << u.first << ' ' << u.second << endl;
            k = dist(sw(u), p[i]);
            if (k != 0) {
                d = min(d, k);
            }
            // cout << d << endl;
        }
        // cout << "finish" << endl;
    }

    cout << d;

    return 0;
}