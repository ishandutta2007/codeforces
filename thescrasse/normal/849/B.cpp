#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x[maxn], y[maxn], g;
array<ll, 2> z, sl[maxn][maxn];
bool visited[maxn];
set<array<ll, 2>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> y[i]; x[i] = i;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            z = {y[i] - y[j], x[i] - x[j]};
            g = __gcd(z[0], z[1]);
            z[0] /= g; z[1] /= g;
            if (z[0] < 0) {
                z[0] *= -1; z[1] *= -1;
            }
            // cout << i << ' ' << j << ' ' << z[0] << ' ' << z[1] << nl;
            sl[i][j] = z;
        }
    }

    for (i1 = 1; i1 < n; i1++) {
        for (i = 1; i < n; i++) visited[i] = false;

        z = sl[0][i1];

        for (j = 1; j < n; j++) {
            if (sl[0][j] == z) visited[j] = true;
        }

        flag[0] = 0;
        for (j = 1; j < n; j++) {
            if (visited[j] == false) {
                // cout << j << nl;
                flag[0] = 1; k = j; break;
            }
        }

        // cout << z[0] << ' ' << z[1] << nl;

        if (flag[0] == 0) {
            continue;
        }

        flag[0] = 1;
        for (j = k + 1; j < n; j++) {
            if (visited[j] == true) continue;
            if (sl[k][j] != z) flag[0] = 0;
        }

        for (i = 2; i < n; i++) {
            s.insert(sl[1][i]);
        }

        if (flag[0] == 1 || s.size() == 1) {
            cout << "Yes"; return 0;
        }
    }

    cout << "No";

    return 0;
}