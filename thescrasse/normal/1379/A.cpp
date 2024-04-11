#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 60

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
string s, o;

char x[7] = {'a', 'b', 'a', 'c', 'a', 'b', 'a'};

bool occ(ll y) {
    ll i;
    flag[9] = 1;
    for (i = 0; i < 7; i++) {
        if (s[i + y] != x[i]) flag[9] = 0;
    }

    if (flag[9] == 1) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> o; flag[1] = 0;
        for (i = 0; i <= n - 7; i++) {
            // cout << "i = " << i << nl;
            s = o; flag[0] = 1;
            for (j = 0; j < 7; j++) {
                // cout << j << ' ' << s[i + j] << nl;
                if (s[i + j] == x[j]) continue;
                else if (s[i + j] == '?') s[i + j] = x[j];
                else flag[0] = 0;
            }

            if (flag[0] == 0) continue;
            flag[5] = 0;
            for (j = 0; j <= n - 7; j++) {
                if (occ(j)) flag[5]++;
            }
            // cout << i << ' ' << flag[5] << nl;
            if (flag[5] == 1) {
                flag[1] = 1; break;
            }
        }

        if (flag[1] == 1) {
            cout << "Yes" << nl;
            for (i = 0; i < n; i++) {
                if (s[i] == '?') cout << 'x';
                else cout << s[i];
            }
            cout << nl;
        } else {
            cout << "No" << nl;
        }
    }

    return 0;
}