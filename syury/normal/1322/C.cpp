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

const int N = (int)5e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, ll> > in(n);
    F(i, 0, n)
        cin >> in[i].Y;
    F(i, 0, m){
        int v, u;
        cin >> v >> u;
        --v; --u;
        in[u].X.pb(v);
    }
    F(i, 0, n){
        sort(all(in[i].X));
    }
    sort(all(in));
    ll g = 0;
    ll cu = in[0].X.empty() ? 0 : in[0].Y;
    F(i, 1, n){
        if(in[i].X.empty())cont;
        if(in[i].X == in[i - 1].X)cu += in[i].Y;
        else{
            g = g ? __gcd(g, cu) : cu;
            cu = in[i].Y;
        }
    }
    g = g ? __gcd(g, cu) : cu;
    cout << g << '\n';
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}