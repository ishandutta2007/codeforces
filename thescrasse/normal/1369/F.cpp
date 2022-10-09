// 1369F
// BareLee

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], ty, l;
bool sl[maxn][2], sf[maxn][2];

bool calc(ll st) {
    // 1 -> LLLLLL
    // 2 -> WWWWWW
    // 3 -> LWLWLW, W even
    // 4 -> LWLWLW, W odd

    l = b[i] + 1; ty = st;
    while (l > a[i]) {
        // cout << "l, ty = " << l _ ty << nl;
        if (ty == 1 || ty == 4) {
            ty = 2;
        } else if (ty == 2) {
            if (l % 2) ty = 4;
            else ty = 3;
        }

        l = (l + 1) / 2;
    }

    // cout << "l, ty = " << l _ ty << nl;

    if (ty == 2 || (ty == 3 && a[i] % 2 == 0) || (ty == 4 && a[i] % 2 == 1)) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sl[i][0] = calc(2); sl[i][1] = calc(1);
    }

    sf[n][0] = sl[n][0]; sf[n][1] = sl[n][1];
    for (i = n - 1; i >= 1; i--) {
        if (sl[i][0] && !sf[i + 1][0]) sf[i][0] = true;
        if (sl[i][1] && sf[i + 1][0]) sf[i][0] = true;
        if (sl[i][0] && !sf[i + 1][1]) sf[i][1] = true;
        if (sl[i][1] && sf[i + 1][1]) sf[i][1] = true;
    }

    /* for (i = 1; i <= n; i++) {
        cout << sl[i][0] _ sl[i][1] << nl;
    }
    cout << nl;

    for (i = 1; i <= n; i++) {
        cout << sf[i][0] _ sf[i][1] << nl;
    }
    cout << nl; */

    cout << sf[1][0] _ sf[1][1] << nl;

    return 0;
}