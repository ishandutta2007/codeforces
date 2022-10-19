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

int main(){
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    vector<int> v;
    rep(i, N){
        if(s[i] == '0' && t[i] == '1') cnt[0]++, v.pb(0);
        if(s[i] == '1' && t[i] == '0') cnt[1]++, v.pb(1);
    }
    if(cnt[0] != cnt[1]) {cout << -1 << endl; return 0;}
    int n = sz(v);
    int sum[n+1];
    sum[0] = 0;
    rep(i, n){
        if(v[i] == 0) sum[i+1] = sum[i]-1;
        else sum[i+1] = sum[i]+1;
    }
    int a = inf, b = -inf;
    rep(i, n+1){
        chmin(a, sum[i]);
        chmax(b, sum[i]);
    }
    cout << b-a << endl;
}