#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[3], b, x, y;
string s[3];

ll eq(ll a, ll b, ll c) {
    if (s[a / 3][a % 3] != s[b / 3][b % 3]) return 0;
    if (s[a / 3][a % 3] != s[c / 3][c % 3]) return 0;
    if (s[a / 3][a % 3] == 'X') return 10;
    else if (s[a / 3][a % 3] == '0') return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    a[0] = 0; a[1] = 0;
    for (i = 0; i < 3; i++) {
        cin >> s[i];
        for (j = 0; j < 3; j++) {
            if (s[i][j] == 'X') a[0]++;
            else if (s[i][j] == '0') a[1]++;
        }
    }

    flag[0] = 0;

    if (a[0] != a[1] && a[0] != a[1] + 1) {
        cout << "illegal"; return 0;
    }

    k = eq(0, 1, 2) + eq(3, 4, 5) + eq(6, 7, 8) + eq(0, 3, 6) + eq(1, 4, 7) + eq(2, 5, 8) + eq(0, 4, 8) + eq(2, 4, 6);

    if (k > 0) {
        if (k % 10 != 0 && k / 10 != 0) cout << "illegal";
        else if (k / 10 != 0 && a[0] != a[1]) cout << "the first player won";
        else if (k % 10 != 0 && a[0] == a[1]) cout << "the second player won";
        else cout << "illegal";
    } else {
        if (a[0] == a[1]) cout << "first";
        else if (a[0] == 5 && a[1] == 4) cout << "draw";
        else cout << "second";
    }

    return 0;
}