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

const int N = (int)1e5;

ll ans[N];
ll d[N];
int divs = 0;
vector<int> who[N];
ll X, k;

void solve(int n, int steps, int & from){
    if(from >= N)ret;
    if(steps == 0){ans[from++] = d[n]; ret;}
    ans[from++] = 1;
    I(x, who[n]){
        solve(x, steps - 1, from);
        if(from >= N)brk;
    }
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> X >> k;
    if(X == 1){cout << 1; ret 0;}
    k = min(k, N * 1ll);
    for(ll i = 2; i * i <= X; i++){
        if(X%i != 0)cont;
        d[divs++] = i;
        if(i * i != X)d[divs++] = X/i;
    }
    d[divs++] = X;
    sort(d, d + divs);
    F(i, 0, divs){
        E(j, 0, i){
            if(d[i]%d[j] == 0)who[i].pb(j);
        }
    }
    int kek = 0;
    solve(divs - 1, k, kek);
    F(i, 0, kek){
        cout << ans[i] << ' ';
    }
    return 0;
}