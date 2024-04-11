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

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

vector<int> gr[N];
dbl P = 0;
int n;

void dfs(int v, int p = -1, int d = 1){
    P += 1.0/d;
    I(u, gr[v]){
        if(u != p)
            dfs(u, v, d + 1);
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n - 1){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    dfs(0);
    cout.precision(10);
    cout << fixed << P << endl;
    return 0;
}