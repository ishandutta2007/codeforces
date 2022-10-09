#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 310

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, l, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        l = 0; r = n - 1; flag[0] = 0;
        for (i = 0; i < n; i++) {
            if (flag[0] == 0) {
                cout << a[l] << ' '; l++;
            } else {
                cout << a[r] << ' '; r--;
            }
            flag[0] ^= 1;
        }

        cout << nl;
    }

    return 0;
}