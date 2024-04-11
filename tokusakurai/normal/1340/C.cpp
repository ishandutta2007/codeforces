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
    vector<int> p(M);
    rep(i, M) cin >> p[i];
    sort(all(p));
    int g, r;
    cin >> g >> r;

    vector<vector<int>> dp(M, vector<int>(g+1, inf));
    dp[0][0] = 0;
    rep(i, M-1){
        int d = p[i+1]-p[i];
        rep(j, g+1){
            if(dp[i][j] == inf) continue;
            int nj = j+d;
            if(nj <= g) chmin(dp[i+1][nj], dp[i][j]);
        }
        rep(j, g+1){
            if(j >= d) chmin(dp[i+1][j], dp[i+1][j-d]);
        }
        dp[i+1][0] = i+1;
    }

    rep3(i, M-2, 0){
        rep(j, g+1){
            chmin(dp[i][j], dp[i+1][j]);
        }
    }

    vector<vector<int>> es(M);
    
    int ptr = 0;
    rep(i, M){
        while(ptr < M && p[ptr] <= p[i]+g) ptr++;
        rep2(j, i+1, ptr-1){
            int k = g+p[j]-p[i];
            if(k&1) continue;
            k >>= 1;
            if(dp[j][k] <= i) es[i].eb(j), es[j].eb(i);
        }
    }

    ll ans = INF;
    queue<int> que;
    vector<ll> d(M, INF);
    d[0] = 0;
    que.emplace(0);

    while(!que.empty()){
        int i = que.front(); que.pop();
        if(N-p[i] <= g) chmin(ans, d[i]*(g+r)+N-p[i]);
        each(e, es[i]){
            if(d[e] == INF) d[e] = d[i]+1, que.emplace(e);
        }
    }

    cout << (ans == INF? -1 : ans) << '\n';
}