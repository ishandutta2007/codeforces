#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x[maxn], p[maxn], hipi, himi, c1, c2;
vector<array<ll, 3>> diff;

void rst() {
    diff.clear(); hipi = -INF; himi = -INF;
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
        cin >> n >> k; rst();
        for (i = 1; i <= n; i++) {
            cin >> x[i] >> p[i];
            diff.pb({x[i] - p[i], 1, 0});
            diff.pb({x[i], -2, 0});
            diff.pb({x[i] + p[i], 1, 0});
        }

        sort(diff.begin(), diff.end());
        for (i = 1; i < diff.size(); i++) {
            diff[i][1] += diff[i - 1][1];
            diff[i][2] = diff[i - 1][2] + ((diff[i][0] - diff[i - 1][0]) * diff[i - 1][1]);
            if (diff[i][2] > k) {
                hipi = max(hipi, diff[i][2] + diff[i][0]);
                himi = max(himi, diff[i][2] - diff[i][0]);
            }

            // cout << "diff" _ diff[i][0] _ diff[i][1] _ diff[i][2] << nl;
        }

        // cout << "hipi, himi =" _ hipi _ himi << nl;

        for (i = 1; i <= n; i++) {
            c1 = k + p[i] + x[i]; c2 = k + p[i] - x[i];
            if (c1 >= hipi && c2 >= himi) cout << 1;
            else cout << 0;
        }
        cout << nl;
    }

    return 0;
}