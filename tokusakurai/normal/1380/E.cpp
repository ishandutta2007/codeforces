#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    rep(i, N) {cin >> a[i]; --a[i];}
    
    vector<int> b;
    int ptr = 0;
    while(ptr < N){
        int j = 0;
        while(ptr+j < N && a[ptr+j] == a[ptr]) j++;
        b.eb(a[ptr]), ptr += j;
    }

    int K = sz(b);
    vector<int> ids[M], chl[M];
    vector<int> deg(M), par(M), root(M);
    rep(i, K) ids[b[i]].eb(i);
    rep(i, M) chl[i].eb(i), deg[i] = sz(ids[i]), par[i] = i, root[i] = i;

    int ans = K-1;
    cout << ans << '\n';
    rep(i, M-1){
        int u, v; cin >> u >> v; u--, v--;
        int p = root[u], q = root[v];

        if(deg[p] < deg[q]){
            each(e, chl[p]){
                each(x, ids[e]){
                    if(x > 0 && par[b[x-1]] == q) ans--;
                    if(x < K-1 && par[b[x+1]] == q) ans--; 
                }
            }
        }
        else{
            swap(p, q);
            each(e, chl[p]){
                each(x, ids[e]){
                    if(x > 0 && par[b[x-1]] == q) ans--;
                    if(x < K-1 && par[b[x+1]] == q) ans--; 
                }
            }
            swap(p, q);
        }
        
        if(sz(chl[p]) > sz(chl[q])){
            each(e, chl[q]) par[e] = p, chl[p].eb(e);
            deg[p] += deg[q];
        }
        else{
            each(e, chl[p]) par[e] = q, chl[q].eb(e);
            deg[q] += deg[p];
            root[u] = q;
        }

        cout << ans << '\n';
    }
}