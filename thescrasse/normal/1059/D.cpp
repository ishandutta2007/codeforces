// 1059D
// Nature Reserve

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (long double)1e15
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k1, t, n, m, res, flag[10], a, b, q;
array<long double, 2> p[maxn];
long double x, y;
__float128 bsl, bsu, bsm, l, r, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cout << fixed << setprecision(20);

    cin >> n; flag[0] = 0; flag[1] = 0;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        if (y > 0) flag[1] = 1;
        else flag[0] = 1;
        p[i] = {x, abs(y)};
    }

    if (flag[0] + flag[1] == 2) {
        cout << -1; return 0;
    }

    bsl = 0; bsu = INF;
    while (clock() < 19 * CLOCKS_PER_SEC / 10) {
        l = -INF; r = INF;
        bsm = (bsl + bsu) / 2;
        for (i = 0; i < n; i++) {
            k = fabsl(p[i][1] - bsm);
            if (bsm < k) {
                l = r + 1; break;
            }
            x = sqrtl(bsm * bsm - k * k);
            l = fmaxl(l, p[i][0] - x); r = fminl(r, p[i][0] + x);
        }

        // cout << bsm << ' ' << l << ' ' << r << nl;

        if (l <= r) bsu = bsm;
        else bsl = bsm;
    }

    cout << fixed << setprecision(20);
    cout << (long double)bsm;

    return 0;
}