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

    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    vector<ll> s1(N+1, 0);
    rep(i, N) s1[i+1] = s1[i]+a[i]*b[i];

    ll ans = 0;
    int L = -1, R = -1;

    rep2(i, 0, 2*N){
        vector<ll> s2(N+1, 0);
        rep(j, N){
            s2[j+1] = s2[j];
            if(0 <= i-1-j && i-1-j < N) s2[j+1] += b[i-1-j]*a[j];
        }

        //rep(j, N+1) cout << s2[j] << ' '; cout << '\n';

        rep2(l, 0, N){
            int r = i-l;
            if(N < r || r < l) continue;
            if(chmax(ans, (s2[r]-s2[l])-(s1[r]-s1[l]))) L = l, R = r;
        }
    }

    //cout << L << ' ' << R << '\n';
    //cout << ans << ' ';
    cout << s1[N]+ans << '\n';
}