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
    int N, M; cin >> N >> M;

    vector<ll> h(N), p(M);
    rep(i, N) cin >> h[i];
    rep(i, M) cin >> p[i];

    ll l = -1, r = 1LL<<40; //(L,R]

    while(r-l > 1){
        ll m = (l+r)/2;

        int ptr = 0;
        rep(i, N){
            if(ptr == M) break;

            if(p[ptr] <= h[i]){
                ll d = h[i]-p[ptr];
                if(d > m) continue;

                ll x = max((m-d)/2, m-2*d);
                ptr = upper_bound(all(p), h[i]+x)-begin(p);
            }
            else{
                ptr = upper_bound(all(p), h[i]+m)-begin(p);
            }
        }

        (ptr == M? r : l) = m;
    }

    cout << r << '\n';
}