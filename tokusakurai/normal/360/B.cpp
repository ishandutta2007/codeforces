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
    int N, K; cin >> N >> K;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    if(N == 1) {cout << "0\n"; return 0;}

    ll L = -1, R = 1LL<<31; //(L, R]

    while(R-L > 1){
        ll M = (L+R)/2;

        vector<int> dp(N);
        rep(i, N) dp[i] = i;

        rep(i, N){
            rep2(j, i+1, N-1){
                if(abs(a[i]-a[j]) <= M*(j-i)){
                    chmin(dp[j], dp[i]+j-i-1);
                }
            }
        }

        rep(i, N) dp[i] += N-1-i;
        
        (*min_element(all(dp)) <= K? R : L) = M;
    }

    cout << R << '\n';
}