// 1282C
// problemi facili, difficili, obbligatori
// idee: prendo tutti i problemi obbligatori, poi quelli facili, poi quelli difficili

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, n, m, res, check1, a[2], b, t, c, neh[2], ta, tc;
vector<pair<long long, long long>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> m;
    for (i1 = 0; i1 < m; i1++) {
        cin >> n >> t >> a[0] >> a[1];
        v.clear();
        neh[0] = 0;
        neh[1] = 0;
        for (i = 0; i < n; i++) {
            cin >> c;
            neh[c]++;
            v.push_back({-1, c});
        }
        for (i = 0; i < n; i++) {
            cin >> c;
            v[i].first = c;
        }
        v.push_back({t + 1, -1});
        sort(v.begin(), v.end());
        /* for (auto u : v) {
            cout << u.first << ' ' << u.second << endl;
        } */
        tc = 0;
        res = 0;
        for (i = 0; i <= n; i++) {
            if (i != 0) {
                tc += a[v[i - 1].second];
                neh[v[i - 1].second]--;
            }
            ta = v[i].first - 1;
            if (ta >= tc) {
                ta -= tc;
                if (ta >= a[0] * neh[0]) {
                    ta -= a[0] * neh[0];
                    res = max(res, i + neh[0] + min(neh[1], ta / a[1]));
                } else {
                    res = max(res, i + ta / a[0]);
                }
            }
            // cout << i << ' ' << v[i].first - 1 << ' ' << tc << ' ' << res << endl;
        }
        cout << res << endl;
    }

    return 0;
}