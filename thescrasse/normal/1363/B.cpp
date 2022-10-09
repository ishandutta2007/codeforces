#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag[2], a, b, x, p, z[1010], o[1010], sz;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> s; sz = s.size();
        z[0] = 0; o[0] = 0;
        for (i = 1; i <= sz; i++) {
            z[i] = z[i - 1] + (s[i - 1] == '0');
            o[i] = i - z[i];
        }

        res = INF;
        for (i = 0; i <= sz; i++) {
            res = min(res, z[i] + o[sz] - o[i]);
            res = min(res, o[i] + z[sz] - z[i]);
        }

        cout << res << endl;
    }

    return 0;
}