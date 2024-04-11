#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)

const int MX = 2e5 + 5;

int tab[300001][20];
int a[300001], c[300001], d[300001];
int get(int x, int up) {
    for(int b = 19; b >= 0; b--) {
        if((1 << b) <= up) {
            up -= (1 << b);
            x = tab[x][b];
        }
    }
    return x;
}
pair<int, ll> query(int st, int take) {
    
    int x = st;
    for(int b = 19; b >= 0; b--) {
        if(a[tab[st][b]] > 0)
            st = tab[st][b];
    }
    pair<int, ll> ans = {0, 0};
    while(take > 0) {
        if(a[st] <= take) {
            ans.first += a[st];
            ans.second += a[st]*1LL*c[st];
            take -= a[st];
            a[st] = 0;
        }
        else if(a[st] > take) {
            ans.first += take;
            ans.second += take*1LL*c[st];
            a[st] -= take;
            take = 0;
        }
        if(st == x) return ans;
        st = get(x, d[x] - d[st] - 1);
    }
    return ans;
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int q, a0, c0; cin >> q >> a0 >> c0;
    a[0] = a0, c[0] = c0;
    for(int i = 1; i <= q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int p, x, y; cin >> p >> x >> y;
            tab[i][0] = p;
            for(int j = 1; j < 20; j++) {
                tab[i][j] = tab[ tab[i][j - 1] ][j - 1];
            }
            a[i] = x;
            c[i] = y;
            d[i] = d[p] + 1;
        }
        else {
            int v, w; cin >> v >> w;
            pair<int, ll> ret = query(v, w);
            cout << ret.f << " " << ret.s << "\n";
        }
    }
}