#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main(){
    int N, K; cin >> N >> K;

    vector<int> a(N);
    rep(i, N) {cin >> a[i]; a[i]--;}

    int l = 0, r = N; //[l,r)

    while(r-l > 1){
        int m = (l+r)/2;
        vector<int> s(N+1, 0);

        rep(i, N){
            s[i+1] = s[i]+(a[i] >= m? 1 : -1);
        }

        vector<int> M(N+1, 0);
        rep2(i, 1, N) M[i] = min(M[i-1], s[i]);

        bool flag = false;
        rep2(i, K, N){
            if(s[i]-M[i-K] > 0) flag = true;
        }

        (flag? l : r) = m;
    }

    cout << l+1 << '\n';
}