#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> a >> b >> n;
    if (a == 0 && b == 0) {
        cout << 1; return 0;
    }
    if (a == 0) {
        cout << "No solution"; return 0;
    }
    if (b % a != 0) {
        cout << "No solution"; return 0;
    }
    b /= a;
    if (b < 0 && n % 2 == 0) {
        cout << "No solution"; return 0;
    }
    k = pow(abs(b), (long double)1 / n);
    // cout << k << nl;
    res = 1;
    for (i = 0; i < n; i++) res *= k;
    if (b < 0) k *= -1;
    if (res == abs(b)) {
        cout << k;
    } else {
        cout << "No solution";
    }

    return 0;
}