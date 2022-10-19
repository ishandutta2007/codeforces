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
    int L, R; cin >> L >> R;

    vector<vector<pii>> es(22);

    rep2(i, 1, 20){
        rep2(j, i+1, 20){
            es[i].eb(j, 1<<(20-j));
        }
        es[i].eb(21, L);
    }
    es[0].eb(21, L);

    int l = L+1, r = R+1;
    rep3(i, 19, 0){
        if(r-l >= (1<<i)){
            es[0].eb(20-i, l-L);
            l += (1<<i);
        }
    }

    int S = 0;
    rep(i, 22) S += sz(es[i]);

    cout << "YES\n";
    cout << 22 << ' ' << S << '\n';

    rep(i, 22){
        each(e, es[i]){
            cout << i+1 << ' ' << e.first+1 << ' ' << e.second << '\n';
        }
    }
}