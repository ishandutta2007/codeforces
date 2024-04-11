//
// Created by yamunaku on 2020/02/12.
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

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    rep(k, m + 1){ // 0..k-1 k..m-1
        int l = m - k;
        vector<vector<int>> f(k + 1, vector<int>(l + 1, false));
        vector<queue<pair<int, int>>> q(26);
        if(k > 0){
            q[t[0] - 'a'].push({1, 0});
        }
        if(l > 0){
            q[t[k] - 'a'].push({0, 1});
        }
        rep(i, n){
            queue<pair<int, int>> nq;
            auto &que = q[s[i] - 'a'];
            while(!que.empty()){
                auto p = que.front();
                que.pop();
                if(!f[p.first][p.second]){
                    f[p.first][p.second] = true;
                    if(p.first < k){
                        if(t[p.first]==s[i]) nq.push({p.first + 1, p.second});
                        else q[t[p.first]-'a'].push({p.first + 1, p.second});
                    }
                    if(p.second < l){
                        if(t[k + p.second]==s[i]) nq.push({p.first, p.second + 1});
                        else q[t[k + p.second] - 'a'].push({p.first, p.second + 1});
                    }
                }
            }
            que = nq;
        }
        if(f[k][l]){
            CYES;
            return;
        }
    }
    CNO;
}

int main(){
    // CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}