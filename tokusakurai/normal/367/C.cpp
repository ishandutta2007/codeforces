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

    int MAX = 10000;
    vector<int> a(MAX+1, 0);

    rep2(i, 0, MAX){
        if(i&1) a[i] = i*(i-1)/2+1;
        else a[i] = i*i/2;
    }

    int K = upper_bound(all(a), N)-begin(a)-1;

    vector<ll> ps;

    rep(i, M){
        int q, c; cin >> q >> c; q--;
        ps.eb(c);
    }

    sort(rall(ps));
    ll ans = 0;
    rep(i, min(M, K)) ans += ps[i];
    cout << ans << '\n';

    /*
    sort(all(ps));
    ll ans = 0;

    for(int i = 0; i < M;){
        int j = 1;
        while(i+j < M && ps[i+j].first == ps[i+j-1].first+1) j++;

        vector<ll> s(j+1, 0);
        rep(k, j) s[k+1] = s[k]+ps[i+k].second;

        rep(k, j+1){
            chmax(ans, s[min(j, k+K)]-s[k]);
        }
        
        i += j;
    }

    cout << ans << '\n';
    */
}