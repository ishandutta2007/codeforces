#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 10010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, r[maxn];
bool visited[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n;

    for (i = 1; i <= n; i++) r[i] = -1;
    j = 1;

    for (i = 2; i <= n; i++) {
        while (j == i || r[j] != -1) j++;
        cout << "?" << ' ' << i << ' ' << j << nf;
        cin >> a;
        cout << "?" << ' ' << j << ' ' << i << nf;
        cin >> b;
        if (a > b) r[i] = a;
        else r[j] = b;
    }

    for (i = 1; i <= n; i++) {
        if (r[i] != -1) visited[r[i]] = true;
        else k = i;
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            r[k] = i; break;
        }
    }

    cout << "! ";
    for (i = 1; i <= n; i++) cout << r[i] << ' ';
    cout << nf;

    return 0;
}