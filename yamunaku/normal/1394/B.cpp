//
// Created by yamunaku on 2020/08/12.
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> e(n);
    int u, v, w;
    rep(i, m){
        cin >> u >> v >> w;
        u--, v--;
        e[u].push_back({w, v});
    }
    mti ok(k, vi(k, true));
    vector<set<pair<int, int>>> from(n);
    rep(i, n){
        sort(all(e[i]));
        int sz = e[i].size();
        rep(j, sz){
            auto &st = from[e[i][j].second];
            if(st.find({sz - 1, j}) != st.end()){
                ok[sz - 1][j] = false;
            }else{
                st.emplace(sz - 1, j);
            }
        }
    }
    vector<vector<vector<pair<int, int>>>> ne(9, vector<vector<pair<int, int>>>(9));
    rep(i, n){
        for(auto &p: from[i]){
            for(auto &q: from[i]){
                if(p.first >= q.first) continue;
                ne[p.first][p.second].push_back(q);
            }
        }
    }
    int ans = 0;
    vi c(k, 0);
    while(1){
        bool can = true;
        rep(i, k){
            if(!ok[i][c[i]]) can = false;
            for(auto &p : ne[i][c[i]]){
                if(c[p.first] == p.second) can = false;
            }
        }
        if(can) ans++;
        rep(i, k){
            if(c[i] < i){
                c[i]++;
                goto next;
            }else{
                c[i] = 0;
            }
        }
        break;
        next:;
    }
    cout << ans << endl;
    return 0;
}