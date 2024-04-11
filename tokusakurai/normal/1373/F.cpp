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
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<ll> a(N), b(N);
        rep(i, N) cin >> a[i];
        rep(i, N) cin >> b[i];
        ll sa = 0, sb = 0;
        rep(i, N) sa += a[i], sb += b[i];
        if(sa > sb) {cout << "NO\n"; continue;}

        vector<ll> S(2*N+1, 0);
        rep(i, 2*N){
            S[i+1] = S[i]+(a[i%N]-b[i%N]);
        }
        vector<ll> M(2*N+2, -INF);
        rep3(i, 2*N, 0){
            M[i] = max(M[i+1], S[i]);
        }

        ll ans = -INF;
        rep(i, N){
            chmax(ans, -b[i]+M[i+1]-S[i+1]);
        }

        cout << (ans <= 0? "YES\n" : "NO\n");
    }
}