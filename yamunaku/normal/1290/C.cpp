//
// Created by yamunaku on 2020/02/02.
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

struct edge{
    int to;
    int w;
};

class UnionFind{
public:
    vector<int> node;
    vector<pair<ll, ll>> p;
    ll ans = 0;

    UnionFind(int n){
        node = vector<int>(n, -1);
        p = vector<pair<ll, ll>>(n, {0, 0});
    }

    void add(int x, ll fir, ll sec){
        x = root(x);
        ans -= min(p[x].first, p[x].second);
        p[x].first += fir;
        p[x].second += sec;
        ans += min(p[x].first, p[x].second);
    }

    int root(int x){
        if(node[x] < 0) return x;
        return node[x] = root(node[x]);
    }

    void uni(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(node[x] > node[y]) swap(x, y);
        ans -= min(p[x].first, p[x].second);
        ans -= min(p[y].first, p[y].second);
        node[x] += node[y];
        node[y] = x;
        p[x].first += p[y].first;
        p[x].second += p[y].second;
        ans += min(p[x].first, p[x].second);
    }
};

int main(){
    CFS;
    int n, m;
    cin >> n >> m;
    string f;
    cin >> f;
    mti s(n);
    rep(i, m){
        int sz, x;
        cin >> sz;
        rep(j, sz){
            cin >> x;
            s[x - 1].push_back(i);
        }
    }
    vector<vector<edge>> e(m);
    rep(i, n){
        if(s[i].size() == 2){
            e[s[i][0]].push_back({s[i][1], f[i] - '0'});
            e[s[i][1]].push_back({s[i][0], f[i] - '0'});
        }
    }
    vi c(m, -1);
    rep(i, m){
        if(c[i] == -1){
            c[i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto &nx:e[x]){
                    if(c[nx.to] != -1) continue;
                    c[nx.to] = c[x] ^ nx.w ^ 1;
                    q.push(nx.to);
                }
            }
        }
    }
    UnionFind uf(m);
    rep(i, m){
        if(c[i] == 0) uf.add(i, 1, 0);
        else uf.add(i, 0, 1);
    }
    rep(i, n){
        if(s[i].size() == 0){
            cout << uf.ans << endl;
            continue;
        }
        if(s[i].size() == 1){
            int k = s[i][0];
            if(c[k] == 0){
                if(f[i] == '1') uf.add(k, IINF, 0);
                else uf.add(k, 0, IINF);
            }else{
                if(f[i] == '0') uf.add(k, IINF, 0);
                else uf.add(k, 0, IINF);
            }
        }else{
            uf.uni(s[i][0], s[i][1]);
        }
        cout << uf.ans << endl;
    }
    return 0;
}