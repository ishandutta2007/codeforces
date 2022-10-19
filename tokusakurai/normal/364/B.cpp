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
    int N, D; cin >> N >> D;

    vector<int> c(N);
    rep(i, N) cin >> c[i];

    int MAX = 500000;

    vector<bool> dp(MAX+1, false);
    dp[0] = true;

    rep(i, N){
        rep3(j, MAX-c[i], 0){
            if(dp[j]) dp[j+c[i]] = true;
        }
    }

    vector<int> nxt(MAX+1, -1);
    rep2(i, 0, D){
        if(dp[i]) nxt[0] = i;
    }

    rep2(i, 1, MAX){
        if(i+D <= MAX && dp[i+D]) nxt[i] = i+D;
        else nxt[i] = nxt[i-1];
    }

    int s = 0, t = 0;
    while(nxt[s] > s){
        s = nxt[s], t++;
    }

    cout << s << ' ' << t << '\n';
}