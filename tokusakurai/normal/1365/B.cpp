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
        int a[N];
        bool e[2];
        e[0] = e[1] = false;
        rep(i, N) cin >> a[i];
        rep(i, N){
            int b; cin >> b;
            e[b] = true;
        }
        if(e[0] && e[1]) cout << "Yes" << endl;
        else{
            bool res = true;
            rep(i, N-1) if(a[i] > a[i+1]) res = false;
            if(res) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}