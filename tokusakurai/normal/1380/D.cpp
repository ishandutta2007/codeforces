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
    ll x, k, y;
    cin >> x >> k >> y;
    vector<int> a(N), b(M);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];
    vector<int> id(N);
    rep(i, N) id[--a[i]] = i;
    rep(i, M) --b[i];

    vector<int> c(M+2);
    c[0] = -1, c[M+1] = N;
    rep(i, M) c[i+1] = id[b[i]];
    rep(i, M+1){
        if(c[i] > c[i+1]) {cout << "-1\n"; return 0;}
    }

    ll ans = 0;
    rep(i, M+1){
        int L = c[i]+1, R = c[i+1]-1, K;
        if(c[i] == -1) K = a[c[i+1]];
        else if(c[i+1] == N) K = a[c[i]];
        else K = max(a[c[i]], a[c[i+1]]);
        
        bool flag = true;
        rep2(j, L, R){
            if(a[j] > K) flag = false;
        }

        int d = R-L+1;
        if(!flag && d < k) {cout << "-1\n"; return 0;}
        ll tmp = x*(d/k)+y*(d%k);
        if(flag) chmin(tmp, y*d);
        else chmin(tmp, x+y*(d-k));
        
        ans += tmp;
    }

    cout << ans << '\n';
}