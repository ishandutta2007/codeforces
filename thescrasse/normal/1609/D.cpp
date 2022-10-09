#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll pr[maxn], sz[maxn], q;
multiset<ll> st;

ll find(ll x) {
    if (x == pr[x]) return x;
    return pr[x] = find(pr[x]);
}

bool same(ll a, ll b) {
    return (find(a) == find(b));
}

void merge(ll a, ll b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    st.erase(st.find(sz[a])); st.erase(st.find(sz[b]));
    pr[b] = a; sz[a] += sz[b];
    st.insert(sz[a]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q; k = 1;

    for (i = 1; i <= n; i++) {
        pr[i] = i; sz[i] = 1; st.insert(1);
    }

    while (q--) {
        cin >> a >> b;
        if (same(a, b)) k++;
        else merge(a, b);

        res = -1; auto it = st.end();
        for (i = 1; i <= k; i++) {
            it--; res += (*it);
        }

        cout << res << nl;
    }

    return 0;
}