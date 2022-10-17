//
// Created by yamunaku on 2020/02/18.
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
    vi a(k);
    rep(i, k) cin >> a[i], a[i]--;
    mti e(n);
    int u, v;
    rep(i, m){
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vi dist(n, IINF);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto &nx:e[now]){
            if(dist[nx] != IINF) continue;
            dist[nx] = dist[now] + 1;
            q.push(nx);
        }
    }
    vi rdist(n, IINF);
    rdist[n - 1] = 0;
    q.push(n - 1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto &nx:e[now]){
            if(rdist[nx] != IINF) continue;
            rdist[nx] = rdist[now] + 1;
            q.push(nx);
        }
    }
    vector<pair<int, int>> p;
    rep(i, k){
        p.push_back({dist[a[i]], a[i]});
    }
    sort(all(p), greater<>());
    int ans = 0;
    int ma = -IINF;
    rep(i, k){
        ans = max(ans, p[i].first + ma + 1);
        ma = max(ma, rdist[p[i].second]);
    }
    cout << min(dist[n - 1], ans) << endl;
    return 0;
}