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

int main(){
    int N;
    cin >> N;
    ll a[N];
    rep(i, N) cin >> a[i];
    map<ll, vector<int>> mp;
    ll cnt[N+1];
    cnt[0] = 0;
    mp[0].pb(0);
    rep(i, N){
        cnt[i+1] = cnt[i]+a[i];
        mp[cnt[i+1]].pb(i+1);
    }
    int next[N+1];
    fill(next, next+N+1, inf);
    for(auto &e: mp){
        rep(i, sz(e.second)-1){
            next[e.second[i]] = e.second[i+1];
        }
    }
    vector<int> v(N+1);
    iota(all(v), 0);
    sort(all(v), [&](int i, int j){
        return next[i] < next[j];
    });
    //rep(i, N+1) cout << next[i] << endl;
    int ptr = 0, ans = 0;
    vector<bool> used(N+1, false);
    for(auto &e: v){
        if(used[e] || next[e] == inf) continue;
        ans++;
        while(ptr < next[e]-1){
            used[ptr++] = true;
        }
        used[e] = true;
    }
    cout << ans << endl;
}