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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;

    a = (n + 2) / 3; b = (n - a + 1) / 2; c = n - a - b;

    if (n == 3) {
        cout << 2 << nl << 1 _ 1 << nl << 1 _ 2 << nl;
        return 0;
    }

    cout << a + c << nl;
    if ((a + c) % 2 == 0) {
        cout << 1 _ 1 << nl;
        for (i = 2; i <= a; i++) cout << i _ a - i + 2 << nl;
        for (i = 1; i <= c; i++) cout << n - i + 1 _ n - c + i << nl;
    } else {
        for (i = 1; i <= a; i++) cout << i _ a - i + 1 << nl;
        for (i = 1; i <= c; i++) cout << n - i + 1 _ n - c + i << nl;
    }

    return 0;
}