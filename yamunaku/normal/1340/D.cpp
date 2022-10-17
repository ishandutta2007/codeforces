//
// Created by yamunaku on 2020/04/23.
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

int n;
mti e;

vector<pair<int, int>> ans;

void dfs(int x, int p, int num){
    ans.emplace_back(x, num);
    int ma = max((int) e[x].size(), num);
    for(auto &c:e[x]){
        if(c == p) continue;
        if(num == ma){
            ans.emplace_back(x, ma - e[x].size());
            num = ma - e[x].size();
        }
        dfs(c, x, ++num);
        ans.emplace_back(x, num);
    }
    if(num == ma){
        ans.emplace_back(x, ma - e[x].size());
        num = ma - e[x].size();
    }
}

int main(){
    CFS;
    cin >> n;
    e = mti(n);
    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    e[0].push_back(-1);
    dfs(0, -1, 0);

    cout << ans.size() << endl;
    for(auto &p : ans){
        cout << p.first + 1 SP p.second << endl;
    }
    return 0;
}