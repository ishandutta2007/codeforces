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

//
int judge1(ll s, ll e){
    while(e%2 == 0 && e/4 >= s) e /= 4;
    if(e%2 == 1) return s%2 == 0;
    if(s > e/2) return s%2;
    return 1;
}

//
int judge2(ll s, ll e){
    if(s > e/2) return 0;
    return judge1(s, e/2)^1; 
}

int main(){
    int N;
    cin >> N;
    int a[N][2];
    rep(i, N){
        ll s, e;
        cin >> s >> e;
        a[i][0] = judge2(s, e), a[i][1] = judge1(s, e);
    }
    int ans[2];
    rep(j, 2){
        int now = j;
        rep3(i, N-1, 0){
            now ^= a[i][now];
        }
        ans[j] = !now;
    }
    cout << ans[1] << ' ' << ans[0] << endl;
}