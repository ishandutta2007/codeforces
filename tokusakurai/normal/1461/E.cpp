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
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    if(k <= r-y) k += y;

    if(x > y){
        ll res;
        if(k < l+x) res = 0;
        else res = 1+(k-(l+x))/(x-y);
        cout << (res >= t? "Yes\n" : "No\n");
        return 0;
    }

    vector<bool> used(x, false);
    ll cnt = 0;

    while(true){
        ll d;
        if(k <= r-y) d = 1;
        else d = (k+x-1-(r-y))/x;
        if(k-d*x < l){
            cnt += (k-l)/x;
            break;
        }
        else{
            k -= d*x, cnt += d;
            k += y;
            if(used[k%x]) {cout << "Yes\n"; return 0;}
            used[k%x] = true;
        }
    }

    cout << (cnt >= t? "Yes\n" : "No\n");
}