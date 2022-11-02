//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6 + 6;

int n, m;
int deg[N];

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    F(i, 0, m){
        int v, u;
        cin >> v >> u;
        --v; --u;
        ++deg[v]; ++deg[u];
    }
    ll ans = 0;
    F(i, 0, n){
        int d = deg[i];
        int nd = n - 1 - d;
        ans += d * 1ll * nd;
    }
    ans /= 2;
    ans = n * 1ll * (n - 1) * 1ll * (n - 2)/6 - ans;
    cout << ans << endl;
    return 0;
}