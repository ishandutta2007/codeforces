#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, x, n) for(ll i = x; i <= n; i++)
#define rep3(i, x, n) for(ll i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
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
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int query(char x, int n){
    cout << x << ' ' << n << endl;
    int ret; cin >> ret;
    return ret;
}

ll ans = 1;
vector<ll> ps1, ps2;
int tmp;
vector<int> cnt;

void solve(int l, int r, bool twice){
    if(twice){
        rep2(i, l, r-1){
            int x = query('A', ps2[i]);
            if(x) ans *= ps2[i];
        }
        return;
    }
    if(l == r) return;
    int m = (l+r)/2;
    rep2(i, l, m) query('B', ps2[i]);
    int del = tmp-query('A', 1);
    if(del == cnt[ps2[m]]) solve(m+1, r, false);
    else solve(l, m+1, true);
}

int main(){
    int N;
    cin >> N;
    vector<bool> p(N+1, true);
    p[0] = p[1] = false;
    cnt.assign(N+1, 0);
    rep2(i, 2, N){
        cnt[i] = cnt[i-1];
        if(!p[i]) continue;
        if(i*i <= N) ps1.pb(i);
        else ps2.pb(i), cnt[i]++;
        for(int j = 2; i*j <= N; j++){
            if(i*i > N && p[i*j]) cnt[i]++;
            p[i*j] = false;
        }
    }
    for(auto &e: ps1) query('B', e);
    for(auto &e: ps1){
        int now = e;
        while(now <= N){
            int x = query('A', now);
            if(x == 0) break;
            ans *= e, now *= e;
        }
    }
    if(ans > 1){
        for(auto &e: ps2){
            if(e*ans > N) break;
            int x = query('A', e*ans);
            if(x) ans *= e;
        }
        cout << "C " << ans << endl;
    }
    else{
        tmp = query('A', 1);
        solve(0, sz(ps2), false);
        cout << "C " << ans << endl;
    }
}