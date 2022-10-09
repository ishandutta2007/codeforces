#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, rps[3];
string s;
map<char, ll> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        f.clear();
        cin >> s; n = s.size();
        for (i = 0; i < n; i++) {
            f[s[i]]++;
        }

        rps[0] = f['R']; rps[1] = f['P']; rps[2] = f['S'];
        if (rps[0] >= rps[1] && rps[0] >= rps[2]) {
            for (i = 0; i < n; i++) {
                cout << "P";
            }
            cout << nl;
        } else if (rps[1] >= rps[0] && rps[1] >= rps[2]) {
            for (i = 0; i < n; i++) {
                cout << "S";
            }
            cout << nl;
        } else {
            for (i = 0; i < n; i++) {
                cout << "R";
            }
            cout << nl;
        }
    }

    return 0;
}