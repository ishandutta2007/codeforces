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
    int T;
    cin >> T;
    rep(t, T){
        int N;
        cin >> N;
        int a[N], b[N];
        rep(i, N) cin >> a[i];
        rep(i, N) cin >> b[i];
        map<pii, int> mp;
        rep(i, N) mp[pii(a[i], a[N-1-i])]++;
        bool res = true;
        rep(i, N){
            pii p = pii(b[i], b[N-1-i]);
            if(mp[p] == 0) res = false;
            else mp[p]--;
        }
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}