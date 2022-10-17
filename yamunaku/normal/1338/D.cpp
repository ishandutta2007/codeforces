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
mti ch;
struct status{
    int sc = 0;
    int id = -1;
};
vector<vector<status>> dp1, dp2;

int ans = 0;

void dfs1(int x, int p){
    for(auto &nx : e[x]){
        if(nx == p) continue;
        ch[x].push_back(nx);
        dfs1(nx, x);
    }
    int sz = ch[x].size();
    dp1[x][0].sc = 1;
    for(auto &c : ch[x]){
        status d1 = {dp2[c][0].sc + 1, c};
        if(d1.sc > dp1[x][0].sc) swap(d1, dp1[x][0]);
        if(d1.sc > dp1[x][1].sc) swap(d1, dp1[x][1]);
        status d2 = {max(dp1[c][0].sc, dp2[c][0].sc) + sz - 1, c};
        if(d2.sc > dp2[x][0].sc) swap(d2, dp2[x][0]);
        if(d2.sc > dp2[x][1].sc) swap(d2, dp2[x][1]);
    }
    ans = max(ans, dp1[x][0].sc);
}

void dfs2(int x, int d1, int d2){
    int sz = ch[x].size();
    for(auto &c : ch[x]){
        int s1, s2;
        if(dp1[x][0].id == c){
            s1 = max(dp1[x][1].sc, d2 + 1);
        }else{
            s1 = max(dp1[x][0].sc, d2 + 1);
        }
        if(dp2[x][0].id == c){
            s2 = max(dp2[x][1].sc - (x == 0 ? 1 : 0), max(d1, d2) + sz - 1);
        }else{
            s2 = max(dp2[x][0].sc - (x == 0 ? 1 : 0), max(d1, d2) + sz - 1);
        }
        ans = max(ans, s1);
        dfs2(c, s1, s2);
    }
    d1 = max(d1, d2 + 1);
    ans = max(ans, d1);
}

int main(){
    CFS;
    int n;
    cin >> n;
    e = mti(n);
    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ch = mti(n);
    dp1 = dp2 = vector<vector<status>>(n, vector<status>(2));
    dfs1(0, 0);
    dfs2(0, 0, 0);
    cout << ans << endl;
    return 0;
}