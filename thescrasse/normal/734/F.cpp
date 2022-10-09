// 734F
// Anton and School

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn], tb[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; k = 0;
    for (i = 0; i < n; i++) {
        cin >> b[i]; k += b[i];
    }
    for (i = 0; i < n; i++) {
        cin >> c[i]; k += c[i];
    }

    k /= (2 * n);

    for (i = 0; i < n; i++) {
        a[i] = (b[i] + c[i] - k) / n;
        if (a[i] < 0) {
            cout << -1; return 0;
        }
    }

    for (j = 0; j < 30; j++) {
        tb[j] = 0;
        for (i = 0; i < n; i++) {
            if ((a[i] >> j) & 1 == 1) {
                tb[j]++;
            }
        }
    }

    flag[0] = 1;

    for (i = 0; i < n; i++) {
        k = 0;
        for (j = 0; j < 30; j++) {
            if ((a[i] >> j) & 1 == 1) {
                k += (1 << j) * tb[j];
            }
        }
        if (k != b[i]) flag[0] = 0;
    }

    for (i = 0; i < n; i++) {
        k = 0;
        for (j = 0; j < 30; j++) {
            if (((a[i] >> j) & 1) == 0) {
                k += (1 << j) * tb[j];
            } else {
                k += (1 << j) * n;
            }
        }
        if (k != c[i]) flag[0] = 0;
    }

    if (flag[0] == 0) {
        cout << -1; return 0;
    }

    for (i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}