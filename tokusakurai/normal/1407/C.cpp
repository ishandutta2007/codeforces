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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int query(int i, int j){
    cout << "? " << i+1 << ' ' << j+1 << endl;
    int ret; cin >> ret;
    return ret;
}

int main(){
    int N;
    cin >> N;
    int ans[N];
    bool used[N];
    fill(used, used+N, false);
    int ptr = 0;
    rep2(i, 1, N-1){
        int a = query(ptr, i), b = query(i, ptr);
        if(a > b){
            ans[ptr] = a, used[a-1] = true, ptr = i;
        }
        else{
            ans[i] = b, used[b-1] = true;
        }
    }
    rep(i, N){
        if(!used[i]) ans[ptr] = i+1;
    }
    cout << "!";
    rep(i, N) cout << ' ' << ans[i];
    cout << endl;
}