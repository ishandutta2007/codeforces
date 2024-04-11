//
// Created by yamunaku on 2019/12/14.
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

vi id;
vi low;
mti e;
vi sz;
int a, b;
ll ans1, ans2;
int f;
int num;

void dfs(int x, int p){
    low[x] = id[x] = num++;
    sz[x] = 1;
    vector<int> ch;
    int pre = f;
    for(auto &nx:e[x]){
        if(nx == p) continue;
        if(id[nx] == -1){
            ch.push_back(nx);
            dfs(nx, x);
            low[x] = min(low[x], low[nx]);
            sz[x] += sz[nx];
            if(x == a && pre == f){
                ans2 += sz[nx];
            }
            pre = f;
        }else{
            low[x] = min(low[x], id[nx]);
        }
    }
    if(x == b){
        f++;
        for(auto &nx:ch){
            if(low[nx] >= id[x]){
                ans1 += sz[nx];
            }
        }
    }
}

int main(){
    CFS;
    int q;
    cin >> q;
    rep(_, q){
        int n, m;
        cin >> n >> m >> a >> b;
        a--, b--;
        e = mti(n);
        low = vi(n, -1);
        id = vi(n, -1);
        sz = vi(n, 0);
        rep(i, m){
            int u, v;
            cin >> u >> v;
            e[u - 1].push_back(v - 1);
            e[v - 1].push_back(u - 1);
        }
        ans1 = ans2 = f = num = 0;
        dfs(a, a);
        cout << ans1*ans2 << endl;
    }
    return 0;
}