#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll r[maxn];
stack<array<ll, 2>> st;

void ins(ll p, ll x) {
    while (!st.empty()) {
        array<ll, 2> c = {st.top()[1], st.top()[0] * flag[0]};
        array<ll, 2> d = {x, p * flag[0]};
        // cout << c[0] _ c[1] _ d[0] _ d[1] << nl;
        if (c < d) st.pop();
        else break;
    }
    if (!st.empty()) r[p] *= (p - st.top()[0]);
    st.push({p, x});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 2; i <= n + 1; i++) {
        cin >> a[i];
    }
    a[1] = INF; a[n + 2] = INF; n += 2; flag[0] = 1;

    for (i = 2; i <= n - 1; i++) r[i] = 1;
    for (i = 1; i <= n; i++) ins(i, a[i]);

    while (!st.empty()) st.pop();
    reverse(a + 1, a + n + 1); reverse(r + 1, r + n + 1); flag[0] = -1;
    for (i = 1; i <= n; i++) ins(i, a[i]);

    for (i = 2; i <= n - 1; i++) {
        res += (a[i] * r[i]);
    }

    for (i = 2; i <= n - 1; i++) {
        r[i] = 1; a[i] *= -1;
    }
    for (i = 1; i <= n; i++) ins(i, a[i]);

    while (!st.empty()) st.pop();
    reverse(a + 1, a + n + 1); reverse(r + 1, r + n + 1); flag[0] = 1;
    for (i = 1; i <= n; i++) ins(i, a[i]);

    for (i = 2; i <= n - 1; i++) {
        res += (a[i] * r[i]);
    }

    cout << res << nl;

    return 0;
}