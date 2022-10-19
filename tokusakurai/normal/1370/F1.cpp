#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX_V = 1e3;
vector<int> es[MAX_V];
vector<int> d(MAX_V);

void dfs(int now, int pre){
    for(auto &e: es[now]){
        if(e == pre) continue;
        d[e] = d[now]+1;
        dfs(e, now);
    }
}

int x, y;

void query(vector<int> &v){
    cout << "? " << sz(v) << ' ';
    for(auto &e: v) cout << e+1 << ' '; cout << endl;
    cin >> x >> y; x--;
    v.clear();
}

int main(){
    int T;
    cin >> T;
    vector<int> v;
    rep(t, T){
        int N;
        cin >> N;
        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            es[u].pb(v), es[v].pb(u);
        }
        rep(i, N) v.pb(i);
        query(v);
        int s = x, R = y;
        fill(all(d), inf), d[s] = 0;
        dfs(s, -1);
        int l = (R+1)/2, r = R+1; //[l,r)
        while(r-l > 1){
            int m = (l+r)/2;
            rep(i, N) if(d[i] == m) v.pb(i);
            if(v.empty()) {r = m; continue;}
            query(v);
            if(y == R) l = m;
            else r = m;
        }
        int a, b;
        rep(i, N) if(d[i] == l) v.pb(i);
        query(v), a = x;
        fill(all(d), inf), d[a] = 0;
        dfs(a, -1);
        rep(i, N) if(d[i] == R) v.pb(i);
        query(v), b = x;
        cout << "! " << a+1 << ' ' << b+1 << endl;
        string res;
        cin >> res;
        rep(i, N) es[i].clear();
    }
}