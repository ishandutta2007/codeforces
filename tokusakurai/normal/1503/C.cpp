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

    vector<pll> p(N);
    rep(i, N){
        ll a, c; cin >> a >> c;
        p[i] = pll(a, c);
    }
    sort(all(p));

    vector<ll> a(N), c(N);
    rep(i, N){
        tie(a[i], c[i]) = p[i];
    }

    vector<int> b(N);
    rep(i, N){
        b[i] = upper_bound(all(a), a[i]+c[i])-begin(a)-1;
    }

    ll ans = accumulate(all(c), 0LL);

    priority_queue<pil> que;
    que.emplace(b[0], -a[0]-c[0]);

    int ptr = 0;
    ll pre = INF;

    while(ptr < N-1){
        int nxt; ll s;
        tie(nxt, s) = que.top(); que.pop();

        if(nxt == ptr){
            while(!que.empty() && que.top().first == nxt){
                chmin(s, que.top().second); que.pop();
            }
            chmin(s, pre);

            pre = INF;

            //cout << ptr << ' ' << a[ptr+1]+s << '\n';
            nxt++;
            ans += a[nxt]+s;
        }
        else{
            pre = s;
        }

        rep2(i, ptr+1, nxt){
            que.emplace(b[i], -a[i]-c[i]);
        }

        ptr = nxt;
    }

    cout << ans << '\n';
}