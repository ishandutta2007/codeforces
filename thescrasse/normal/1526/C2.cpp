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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll tt;
priority_queue<ll> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    res = n;
    for (i = 1; i <= n; i++) {
        tt += a[i]; pq.push(-a[i]);
        while (tt < 0) {
            k = pq.top(); pq.pop();
            tt += k; res--;
        }
    }

    cout << res << nl;

    return 0;
}