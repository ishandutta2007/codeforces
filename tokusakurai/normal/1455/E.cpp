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

ll query(ll a, ll b, ll c, ll d){
    ll p[] = {a, b, c, d};
    sort(p, p+4);
    ll ret = 0;
    rep(i, 4) ret += abs(p[i]-p[1]);
    return ret;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ll x[4], y[4];
        rep(i, 4) cin >> x[i] >> y[i];
        ll ans = INF;

        rep(i, 4) rep(j, 4) rep(k, 4){
            if(i == j) continue;
            ll sx = x[i], sy = y[j];
            if(k != i && k != j){
                int l = 0;
                rep(m, 4) if(m != i && m != j && m != k) l = m;
                ll tmp = abs(x[k]-sx)+abs(y[k]-sy);
                ll a = y[i]-sy, b = x[j]-sx, c = y[l]-sy, d = x[l]-sx;
                tmp += min(query(a, b, c, d), query(a, -b, c, -d));
                chmin(ans, tmp);
            }
            else if(k == i){
                rep(l, 4){
                    if(l == i || l == j) continue;
                    ll tmp = abs(y[i]-sy)+abs(x[l]-sx);
                    int m = 0;
                    rep(n, 4) if(n != i && n != j && n != l) m = n;
                    ll a = y[l]-sy, b = x[j]-sx, c = y[m]-sy, d = x[m]-sx;
                    tmp += min(query(a, b, c, d), query(a, -b, c, -d));
                    chmin(ans, tmp);
                }
            }
            else{
                rep(l, 4){
                    if(l == i || l == j) continue;
                    ll tmp = abs(x[j]-sx)+abs(y[l]-sy);
                    int m = 0;
                    rep(n, 4) if(n != i && n != j && n != l) m = n;
                    ll a = y[i]-sy, b = x[l]-sx, c = y[m]-sy, d = x[m]-sx;
                    tmp += min(query(a, b, c, d), query(a, -b, c, -d));
                    chmin(ans, tmp);
                }
            }
        }

        rep(i, 4) rep(j, 4) rep(k, 4){
            if(i == j || j == k || k == i) continue;
            int l = 0;
            rep(m, 4) if(m != i && m != j && m != k) l = m;
            ll sx = x[i], sy = y[i];
            ll tmp = abs(x[j]-sx)+abs(y[k]-sy);
            ll a = y[j]-sy, b = x[k]-sx, c = y[l]-sy, d = x[l]-sx;
            tmp += min(query(a, b, c, d), query(a, -b, c, -d));
            chmin(ans, tmp);
        }

        cout << ans << '\n';
    }
}