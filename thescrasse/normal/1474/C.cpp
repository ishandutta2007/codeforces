#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

int i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, mx;
multiset<int> st;
vector<array<int, 2>> rs;

void rst() {
    st.clear(); rs.clear();
    for (int i = 1; i <= n; i++) st.insert(a[i]);
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
        cin >> n; n *= 2;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        for (i = 1; i <= n - 1; i++) {
            flag[0] = 0; flag[1] = 1; rst();
            while (!st.empty()) {
                auto it = st.end();
                it--; mx = (*it);
                if (flag[0] == 0) {
                    k = a[i] + mx; flag[0] = 1;
                }

                // cout << k _ mx << nf;

                st.erase(st.find(mx));

                if (st.count(k - mx) == 0) {
                    flag[1] = 0; break;
                }

                st.erase(st.find(k - mx));
                rs.pb({mx, k - mx}); k = mx;
            }

            if (flag[1] == 1) {
                cout << "YES" << nl;
                cout << a[i] + a[n] << nl;
                for (auto u : rs) cout << u[0] _ u[1] << nl;
                break;
            }
        }

        if (flag[1] == 0) cout << "NO" << nl;
    }

    return 0;
}