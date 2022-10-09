#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        flag[0] = 0; flag[1] = 0; flag[2] = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0) {
                if (a[i] < a[i - 1]) flag[2] = 1;
            }
        }
        for (i = 0; i < n; i++) {
            cin >> b[i];
            flag[b[i]] = 1;
        }

        if (flag[0] + flag[1] == 2 || flag[2] == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}