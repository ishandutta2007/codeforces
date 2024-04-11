#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e10
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[3], b, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> a[0] >> a[1] >> a[2];
    cout << "First" << nf;
    cout << INF << nf;
    cin >> x;
    if (x == 0) return 0;
    a[x - 1] += INF;
    k = 3 * a[x - 1] - a[0] - a[1] - a[2];
    cout << k << nf;
    cin >> x;
    if (x == 0) return 0;
    a[x - 1] += k;
    k = max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]});
    k /= 2;
    cout << k << nf;

    return 0;
}