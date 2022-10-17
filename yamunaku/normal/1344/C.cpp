//
// Created by yamunaku on 2020/05/06.
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

int main(){
    CFS;
    int n, m;
    cin >> n >> m;
    mti e(n), re(n);
    vi deg(n, 0);
    int u, v;
    rep(i, m){
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        re[v].push_back(u);
        deg[v]++;
    }
    vi ord(n);
    queue<int> q;
    rep(i, n) if(deg[i] == 0) q.push(i);
    rep(i, n){
        if(q.empty()){
            cout << -1 << endl;
            return 0;
        }
        int now = q.front();
        q.pop();
        ord[i] = now;
        for(auto &nx:e[now]){
            deg[nx]--;
            if(deg[nx] == 0) q.push(nx);
        }
    }
    string ans(n, 'E');
    vi dp(n), rdp(n);
    iota(all(dp), 0);
    iota(all(rdp), 0);
    rep(i, n){
        int now = ord[i];
        for(auto &nx:re[now]){
            dp[now] = min(dp[now], dp[nx]);
        }
    }
    rep(i, n){
        int now = ord[n - 1 - i];
        for(auto &nx:e[now]){
            rdp[now] = min(rdp[now], rdp[nx]);
        }
    }
    int count = 0;
    rep(i, n){
        if(dp[i] == i && rdp[i] == i){
            count++;
            ans[i] = 'A';
        }
    }
    cout << count << "\n" << ans << endl;
    return 0;
}