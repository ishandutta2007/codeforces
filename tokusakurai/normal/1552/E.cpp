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

    vector<int> c(N*K);
    rep(i, N*K){
        cin >> c[i]; c[i]--;
    }

    vector<pii> ans(N, {-1, -1});
    int C = N;

    while(C > 0){
        vector<int> pre(N, -1);
        rep(i, N*K){
            if(ans[c[i]].first != -1) continue;

            if(pre[c[i]] == -1) pre[c[i]] = i;
            else{
                ans[c[i]] = pii(pre[c[i]], i);
                fill(all(pre), -1);
                C--;
            }
        }
    }

    rep(i, N){
        cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';
    }
}