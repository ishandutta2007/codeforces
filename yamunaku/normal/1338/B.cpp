//
// Created by yamunaku on 2020/04/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

mti e;
vi deg;

int f = 0;

void dfs(int x, int p, int d){
    if(deg[x] == 1) f |= d;
    for(auto &nx : e[x]){
        if(nx == p) continue;
        dfs(nx, x, 3 - d);
    }
}

int main(){
    CFS;
    int n;
    cin >> n;
    e = mti(n);
    deg = vi(n);
    vi x, y;
    vi count(n);
    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++, deg[v]++;
        x.push_back(u), y.push_back(v);
    }
    dfs(0, 0, 1);
    if(f == 3) cout << "3 ";
    else cout << "1 ";
    int ans = n - 1;
    rep(i, n){
        if(deg[i] == 1) count[e[i][0]]++;
    }
    rep(i, n){
        ans -= max(0, count[i] - 1);
    }
    cout << ans << endl;
    return 0;
}