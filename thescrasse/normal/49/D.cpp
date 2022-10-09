#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s;

    for (i = 0; i < n; i++) {
        a[i] = (ll)s[i] - 48;
    }

    res = INF;
    for (k = 0; k < 2; k++) {
        m = 0;
        for (i = 0; i < n; i++) {
            if (a[i] != ((i + k) % 2)) m++;
        }

        res = min(res, m);
    }

    cout << res;

    return 0;
}