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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5;

vector<vector<int> > gr;
int mx = 0;
int pos;
int b;
int kek;
int diam;

void findmax(int v, bool isb, int p = -1, int d = 0){
    if(mx < d){mx = d; pos = v;}
    if(v == b && isb)kek = d;
    for(auto u: gr[v]){
        if(u != p){
            findmax(u, isb, v, d + 1);
        }
    }
}

void calc_diam(){
    mx=0;
    findmax(0, false);
    mx=0;
    findmax(pos, false);
    diam = mx;
}

void solve(){
    int n, a, da, db;
    cin >> n >> a >> b >> da >> db;
    --a; --b;
    gr = vector<vector<int> >(n);
    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    if(2 * da >= db){
        cout << "Alice\n";
    }
    else{
        mx = 0;
        findmax(a, true);
        calc_diam();
        if(kek <= da || diam <= 2*da){
            cout << "Alice\n";
        }
        else cout << "Bob\n";
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}