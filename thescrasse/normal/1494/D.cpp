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
     
    ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
    ll mt[maxn][maxn], cr[maxn], wg[maxn], w, parent[maxn];
    vector<array<ll, 3>> v;
     
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
     
        #if !ONLINE_JUDGE && !EVAL
            ifstream cin("input.txt");
            ofstream cout("output.txt");
        #endif
     
        cin >> n;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cin >> mt[i][j]; v.pb({mt[i][j], i, j});
            }
        }
     
        for (i = 1; i <= 3 * n; i++) {
            cr[i] = i; wg[i] = -1; parent[i] = i;
        }
        k = n + 1;
     
        sort(v.begin(), v.end());
     
        for (auto u : v) {
            a = u[1]; b = u[2]; w = u[0];
            // cout << a _ b _ w << nl;
            if (a == b) {
                wg[a] = w; continue;
            }
     
            while (parent[cr[a]] != cr[a]) cr[a] = parent[cr[a]];
            while (parent[cr[b]] != cr[b]) cr[b] = parent[cr[b]];
     
            if (wg[cr[b]] == w) swap(a, b);
     
            // cout << cr[a] _ cr[b] << nl;
            if (wg[cr[a]] == w) {
                parent[cr[b]] = cr[a];
            } else {
                parent[cr[a]] = k; parent[cr[b]] = k; wg[k] = w; k++;
            }
        }
     
        k--;
        cout << k << nl;
        for (i = 1; i <= k; i++) cout << wg[i] << ' ';
        cout << nl;
     
        cout << k << nl;
        for (i = 1; i <= k - 1; i++) {
            cout << i _ parent[i] << nl;
        }
     
        return 0;
    }