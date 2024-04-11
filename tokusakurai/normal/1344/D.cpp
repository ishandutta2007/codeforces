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
    int N;
    ll K;
    cin >> N >> K;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    ll L = -(1LL<<62), R = (1LL<<30); //[L, R)
    while(R-L > 1){
        ll M = (L+R)/2;
        ll cnt = 0;
        rep(i, N){
            ll l = -1, r = a[i]; //(l, r]
            while(r-l > 1){
                ll m = (l+r)/2;
                if(a[i]-3*m*(m+1)-1 < M) r = m;
                else l = m;
            }
            cnt += r;
        }
        if(cnt >= K) L = M;
        else R = M;
    }

    ll cnt = 0;
    vector<ll> ans(N);
    vector<bool> flag(N, false);
    rep(i, N){
        ll l = -1, r = a[i]; //(l, r]
        while(r-l > 1){
            ll m = (l+r)/2;
            if(a[i]-3*m*(m+1)-1 < L) r = m;
            else l = m;
        }
        cnt += r;
        ans[i] = r;
        if(r > 0 && a[i]-3*(r-1)*r-1 == L) flag[i] = true;
    }

    cnt -= K;
    rep(i, N){
        if(cnt == 0) break;
        if(!flag[i]) continue;
        cnt--, ans[i]--;
    }

    rep(i, N) cout << ans[i] << ' '; cout << '\n';
}