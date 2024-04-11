#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, l;
bool visited[300010];
vector<ll> nv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        visited[a[i]] = true;
    }

    for (i = 0; i < 3 * n; i++) {
        if (visited[i] == false) nv.pb(i);
    }

    l = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            cout << nv[l] << ' '; l++;
        } else if (a[i] > a[i - 1]) {
            cout << a[i - 1] << ' ';
        } else {
            cout << nv[l] << ' '; l++;
        }
    }

    return 0;
}