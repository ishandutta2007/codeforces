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
    int N, H, M, K;
    cin >> N >> H >> M >> K;
    map<int, int> mp;
    vector<int> ms;
    int h[N], m[N];
    rep(i, N){
        cin >> h[i] >> m[i];
        int e = m[i]%(M/2);
        if(!mp.count(e)) ms.pb(e);
        if(!mp.count(e+(M/2))) ms.pb(e+(M/2));
        mp[e]++, mp[e+(M/2)]++;
    }
    sort(all(ms));
    int n = sz(ms)/2;
    int cnt = 0, now = 0;
    while(ms[now] < K-1){
        cnt += mp[ms[now++]];
    }
    int ans = cnt, t = M/2-1;
    rep(i, n){
        cnt -= mp[ms[i]];
        while(ms[now] < ms[i]+K){
            cnt += mp[ms[now++]];
        }
        if(chmin(ans, cnt)) t = ms[i];
    }
    cout << ans << ' ' << (t+K)%(M/2) << endl;
    rep(i, N){
        int a1 = m[i], a2 = (m[i]+M/2)%M;
        if((t < a1 && a1 < t+K) || (t < a2 && a2 < t+K)) cout << i+1 << ' '; 
    }
    cout << endl;
}