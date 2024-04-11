#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

ll mpow(ll x, ll n, ll m){
    ll ret = 1;
    while(n){
        if(n&1) ret *= x, ret %= m;
        x *= x, x %= m;
        n >>= 1;
    }
    return ret;
}

int main(){
    int N, P;
    cin >> N >> P;
    int cnt[2001];
    fill(cnt, cnt+2001, 0);
    rep(i, N){
        int a; cin >> a;
        cnt[a]++;
    }
    int power[2001];
    fill(power, power+2001, 0);
    rep2(i, 1, 2000){
        int memo = i;
        while(memo%P == 0) memo /= P, power[i]++;
    }
    rep2(i, 1, 2000) cnt[i] += cnt[i-1];
    vector<int> ans;
    rep2(i, 0, 2000){
        int sum = 0;
        rep(j, N){
            int k = cnt[min(i+j, 2000)]-j;
            if(k <= 0) {sum = 1; break;}
            sum += power[k];
        }
        if(sum == 0) ans.pb(i);
    }
    cout << sz(ans) << endl;
    for(auto &e: ans) cout << e << ' '; cout << endl;
}