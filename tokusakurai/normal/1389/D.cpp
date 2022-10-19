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
        ll N, K;
        cin >> N >> K;
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2) swap(l1, l2), swap(r1, r2);
        if(r1 > r2) swap(r1, r2);

        if(r1 > l2) K -= (r1-l2)*N;

        if(r1 < l2){
            ll ans = INF, tmp = 0;
            ll d = r2-l1;
            rep(i, N){
                if(K <= 0) break;
                tmp += l2-r1;
                tmp += min(K, d), K -= d;
                chmin(ans, tmp+2*max(K, 0LL));
            }
            cout << ans << '\n';
        }
        else{
            ll ans = 0;
            ll d = l2-l1+r2-r1;
            rep(i, N){
                if(K <= 0) break;
                ans += min(K, d); K -= d;
            }
            if(K > 0) ans += 2*K;
            cout << ans << '\n';
        }
    }
}