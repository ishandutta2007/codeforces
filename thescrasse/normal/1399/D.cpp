#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, r[maxn];
string s;
vector<ll> l[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        l[0].clear(); l[1].clear();
        cin >> n >> s; k = 1;
        for (i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (l[1].empty()) {
                    l[0].pb(k); r[i] = k; k++;
                } else {
                    a = l[1].back(); l[1].pop_back();
                    l[0].pb(a); r[i] = a;
                }
            } else {
                if (l[0].empty()) {
                    l[1].pb(k); r[i] = k; k++;
                } else {
                    a = l[0].back(); l[0].pop_back();
                    l[1].pb(a); r[i] = a;
                }
            }
        }

        cout << k - 1 << nl;
        for (i = 0; i < n; i++) {
            cout << r[i] << ' ';
        }
        cout << nl;
    }

    return 0;
}