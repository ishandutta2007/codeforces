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
    int N; cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(rall(a));

    int M; cin >> M;
    vector<char> p(M);
    vector<int> t(M);
    rep(i, M) cin >> p[i] >> t[i];

    vector<int> dp(1<<M, 0);
    vector<int> pre(1<<M, inf);
    rep(i, 1<<M){
        rep(j, M){
            if((i>>j)&1) continue;
            chmin(pre[i], j);
        }
    }

    //rep(i, 1<<M) cout << pre[i] << ' '; cout << '\n';

    rep3(i, M-1, 0){
        int x = (t[i] == 1? -inf : inf);
        vector<int> tmp(1<<M, x);
        rep(j, 1<<M){
            if(t[i] == 1){
                if(p[i] == 'p'){
                    if(pre[j] != inf){
                        chmax(tmp[j], dp[j|(1<<pre[j])]+a[pre[j]]);
                    }
                }
                else{
                    rep(k, M){
                        if((j>>k)&1) continue;
                        chmax(tmp[j], dp[j|(1<<k)]);
                    }
                }
            }
            else{
                if(p[i] == 'p'){
                    if(pre[j] != inf){
                        chmin(tmp[j], dp[j|(1<<pre[j])]-a[pre[j]]);
                    }
                }
                else{
                    rep(k, M){
                        if((j>>k)&1) continue;
                        chmin(tmp[j], dp[j|(1<<k)]);
                    }
                }
            }
        }
        swap(dp, tmp);
    }

    cout << dp[0] << '\n';
}