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
    ll N, M, K; cin >> N >> M >> K;

    vector<int> a(N), b(M);
    vector<int> ida(2*max(N, M), -1), idb(2*max(N, M), -1);

    rep(i, N){
        cin >> a[i]; a[i]--;
        ida[a[i]] = i;
    }
    rep(i, M){
        cin >> b[i]; b[i]--;
        idb[b[i]] = i;
    }

    vector<ll> ids(M, INF);
    for(ll i = 0; i < M; i++){
        chmin(ids[(i*N)%M], i);
    }

    ll G = gcd(N, M), L = lcm(N, M);
    ll gn = N/G, gm = M/G;

    vector<ll> pos(2*max(N, M), -1);
    vector<int> v;

    rep(i, 2*max(N, M)){
        ll A = ida[i], B = idb[i];
        if(A == -1 || B == -1) continue;
        ll C = (N*M+B-A)%M;

        if(ids[C] == INF) continue;
        ll x = ids[C];
        ll y = (x*N+A-B)/M;

        if(y < 0) x += gm, y += gn;
        ll st = x*N+A;
        pos[i] = st;
        v.eb(i);

        //if(st >= m) continue;
        //cnt += (m-st+L-1)/L;
    }

    //rep(i, M) cout << ids[i] << ' '; cout << '\n';
    //each(i, v) cout << i << ' ' << pos[i] << '\n';

    ll l = 0, r = INF; //(l, r]
    while(r-l > 1){
        ll cnt = 0, m = (l+r)/2;

        each(i, v){
            if(pos[i] < m) cnt += (m-pos[i]+L-1)/L;
            if(cnt > m-K) break;
        }

        (m-cnt >= K? r : l) = m;
    }

    cout << r << '\n';
}