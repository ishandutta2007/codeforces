//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;
const ll inf = (ll)4e18;

int sz[3];
ll a[3][N];

inline ll sq(ll x){
    ret x * x;
}

void solve(){
    scanf("%d%d%d", sz, sz + 1, sz + 2);
    F(c, 0, 3){
        F(i, 0, sz[c])
            scanf("%lld", a[c] + i);
        sort(a[c], a[c] + sz[c]);
    }
    vector<int> p = {0, 1, 2};
    ll ans = inf;
    do{
        ll * x = a[p[0]], * y = a[p[1]], * z = a[p[2]];
        int j = 0, k = 0;
        F(i, 0, sz[p[0]]){
            while(j < sz[p[1]] && y[j] <= x[i])
                ++j;
            if(j > 0){
                while(k < sz[p[2]] && z[k] < x[i])++k;
                if(k < sz[p[2]]){
                    ans = min(ans, sq(x[i] - y[j - 1]) + sq(y[j - 1] - z[k]) + sq(z[k] - x[i]));
                }
            }
        }
    }while(next_permutation(all(p)));
    printf("%lld\n", ans);
}

int main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}