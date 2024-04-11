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
    int A[N];
    rep(i, N) cin >> A[i];
    int MAX = 1e6;
    vector<bool> used(MAX, false), able(MAX, true);
    rep(i, N) able[A[i]] = false;
    int now1 = 0, now2 = 0, ans[N];
    rep(i, N){
        if(now1 == A[i]){
            while(!able[now2]) now2++;
            ans[i] = now2;
            able[now2] = false;
            used[now2] = true;
        }
        else{
            ans[i] = now1;
            used[now1] = true;
            able[now1] = false;
            while(used[now1]) now1++;
            if(now1 != A[i]) {cout << -1 << endl; return 0;}
        }
    }
    rep(i, N) cout << ans[i] << ' '; cout << endl;
}