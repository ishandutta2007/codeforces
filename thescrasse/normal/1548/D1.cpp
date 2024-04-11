#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll cn[4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a % 4 == 0 && b % 4 == 0) cn[0]++;
        if (a % 4 == 0 && b % 4 == 2) cn[1]++;
        if (a % 4 == 2 && b % 4 == 0) cn[2]++;
        if (a % 4 == 2 && b % 4 == 2) cn[3]++;
    }

    for (i = 0; i <= 3; i++) {
        res += ((cn[i] * (cn[i] - 1) * (n - cn[i])) / 2);
        res += ((cn[i] * (cn[i] - 1) * (cn[i] - 2)) / 6);
    }

    cout << res << nl;

    return 0;
}