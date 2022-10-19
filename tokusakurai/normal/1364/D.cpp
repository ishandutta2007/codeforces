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

const int MAX_V = 2e5;
vector<int> used(MAX_V, 0);
vector<int> es[MAX_V];
vector<int> loop;
int twice = -1;

void dfs(int now, int pre){
    if(used[now]) twice = now;
    else{
        used[now]++;
        for(auto &e: es[now]){
            if(e == pre) continue;
            dfs(e, now);
            if(twice >= 0){
                loop.pb(now);
                if(twice == now) twice = -2;
                break;
            }
            elif(twice == -2) break;
        }
        used[now]--;
    }
}

//loop
bool find_loop(){
    rep(i, MAX_V){
        dfs(i, -1);
        if(!loop.empty()) return true;
    }
    return false;
}

int col[MAX_V];
vector<int> ans, ans2;

void dfs2(int now, int pre){
    if(pre == -1 || col[pre] == 0){
        col[now] = 1;
        ans.pb(now);
    }
    else ans2.pb(now);
    for(auto &e: es[now]){
        if(e != pre) dfs2(e, now);
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    fill(col, col+MAX_V, 0);
    if(M == N-1){
        dfs2(0, -1);
        if(sz(ans) < sz(ans2)) swap(ans, ans2);
        cout << 1 << endl;
        rep(i, (K+1)/2) cout << ans[i]+1 << ' '; cout << endl;
    }
    else{
        find_loop();
        int id[MAX_V];
        fill(id, id+MAX_V, -1);
        int n = sz(loop);
        rep(i, n) id[loop[i]] = i;
        int l = 0, r = n-1;
        rep(i, n){
            if(i == r) break;
            for(auto &e: es[loop[i]]){
                if(id[e] <= i+1 || id[e] > r) continue;
                l = i, r = id[e];
            }
        }
        vector<int> res;
        rep2(i, l, r) res.pb(loop[i]);
        int k = sz(res);
        if(k <= K){
            cout << 2 << endl;
            cout << k << endl;
            for(auto &e: res) cout << e+1 << ' '; cout << endl;
        }
        else{
            cout << 1 << endl;
            rep(i, (K+1)/2) cout << res[2*i]+1 << ' '; cout << endl;
        }
    }
}