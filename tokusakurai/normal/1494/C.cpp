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

int solve(vector<int> a, vector<int> b){
    int n = sz(a), m = sz(b);

    set<int> s;
    each(e, b) s.emplace(e);

    vector<int> dp1(n+1, 0);
    rep(i, n){
        dp1[i+1] = dp1[i]+s.count(a[n-1-i]);
    }

    vector<int> dp2(n+1, 0);
    int ptr = 0;
    rep(i, n){
        dp2[i+1] = dp2[i];
        while(ptr < m && b[ptr] < a[i]) ptr++;
        if(ptr == m) continue;

        while(ptr < m && (i == n-1 || b[ptr] < a[i+1])){
            int x = lower_bound(all(b), b[ptr]+1)-lower_bound(all(b), b[ptr]-i);
            chmax(dp2[i+1], x);
            ptr++;
        }
    }

    //rep(i, n+1) cout << dp1[i] << ' '; cout << '\n';
    //rep(i, n+1) cout << dp2[i] << ' '; cout << '\n';

    int ret = 0;
    rep(i, n+1){
        chmax(ret, dp1[i]+dp2[n-i]);
    }

    return ret;
}

int main(){
    int T; cin >> T;

    while(T--){
        int N, M; cin >> N >> M;

        vector<int> a(N), b(M);
        rep(i, N) cin >> a[i];
        rep(i, M) cin >> b[i];

        vector<int> la, ra, lb, rb;
        rep(i, N){
            if(a[i] < 0) la.eb(-a[i]);
            else ra.eb(a[i]);
        }
        rep(i, M){
            if(b[i] < 0) lb.eb(-b[i]);
            else rb.eb(b[i]);
        }

        reverse(all(la)), reverse(all(lb));

        //cout << solve(ra, rb) << '\n';
        cout << solve(la, lb)+solve(ra, rb) << '\n';
    }
}