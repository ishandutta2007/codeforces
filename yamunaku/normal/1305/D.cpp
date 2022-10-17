//
// Created by yamunaku on 2020/03/03.
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

int query(int u, int v){
    cout << "?" SP u + 1 SP v + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}

int main(){
    //CFS;
    int n;
    cin >> n;
    mti e(n);
    int u, v;
    vi deg(n, 0);
    rep(i, n - 1){
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[v]++, deg[u]++;
    }
    queue<int> q;
    rep(i, n){
        if(deg[i] == 1) q.push(i);
    }
    while(q.size() >= 2){
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();
        int ans = query(u, v);
        if(ans == u || ans == v){
            cout << "!" SP ans + 1 << endl;
            return 0;
        }
        for(auto &x:e[u]){
            deg[x]--;
            if(deg[x] == 1) q.push(x);
        }
        for(auto &x:e[v]){
            deg[x]--;
            if(deg[x] == 1) q.push(x);
        }
    }
    cout << "!" SP q.front() + 1 << endl;
    return 0;
}