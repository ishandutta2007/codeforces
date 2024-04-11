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
    ll A, B; cin >> A >> B;

    string S, T; cin >> S >> T;
    ll N = sz(S), M = sz(T), G = gcd(N, M);
    ll L = (N*A)/(N*M/G);

    vector<ll> cnt1(26, 0), cnt2(26, 0);
    ll ans = N*A;

    rep(i, G){
        fill(all(cnt1), 0), fill(all(cnt2), 0);

        for(int j = i; j < N; j += G){
            cnt1[S[j]-'a']++;
        }
        for(int j = i; j < M; j += G){
            cnt2[T[j]-'a']++;
        }

        rep(i, 26) ans -= cnt1[i]*cnt2[i]*L;
    }

    cout << ans << '\n';
}