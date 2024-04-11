#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

int i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, q;
ll x;
map<vector<int>, int> mp;

void enc(int n) {
    int i;
    map<int, int> f;
    vector<int> v;
    k = n;
    for (i = 2; i * i <= n; i++) {
        while (k % i == 0) {
            k /= i; f[i]++;
        }
    }
    if (k != 1) f[k]++;

    v.pb(-1);
    for (auto u : f) {
        if (u.second % 2) v.pb(u.first);
    }

    mp[v]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; mp.clear(); res = 0; m = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; enc(a[i]);
        }

        for (auto u : mp) {
            m = max(m, u.second);
            if (u.first.size() == 1 || u.second % 2 == 0) res += u.second;
        }

        cin >> q;
        while (q--) {
            cin >> x;
            if (x == 0) cout << m << nl;
            else cout << max(m, res) << nl;
        }
    }

    return 0;
}