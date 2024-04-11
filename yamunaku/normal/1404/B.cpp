//
// Created by yamunaku on 2020/08/27.
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

void solve(){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    e = mti(n);
    a--, b--;
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(db <= 2 * da){
        cout << "Alice" << endl;
        return;
    }
    queue<int> q;
    vi d(n, IINF);
    q.push(a);
    d[a] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto &nx : e[x]){
            if(d[nx] != IINF) continue;
            d[nx] = d[x] + 1;
            q.push(nx);
        }
    }
    if(d[b] <= da){
        cout << "Alice" << endl;
        return;
    }
    int ma = a;
    rep(i,n){
        if(d[ma] < d[i]) ma = i;
    }
    d=vi(n, IINF);
    q.push(ma);
    d[ma] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto &nx : e[x]){
            if(d[nx] != IINF) continue;
            d[nx] = d[x] + 1;
            q.push(nx);
        }
    }
    rep(i,n){
        if(d[ma] < d[i]) ma = i;
    }
    if(d[ma] <= 2*da) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main() {
     CFS;

    int t;
    cin >> t;
    rep(_,t) solve();
    return 0;
}