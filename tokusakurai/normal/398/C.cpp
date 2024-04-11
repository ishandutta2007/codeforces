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
    int N; cin >> N;

    if(N%2 == 0){
        int n = N/2;
        cout << 1 << ' ' << n+1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << ' ' << 2*n-3 << '\n';
        rep2(i, 2, n){
            cout << i << ' ' << n+i << ' ' << 1 << '\n';
        }
        rep2(i, 2, n-1){
            cout << i << ' ' << i+1 << ' ' << n-i << '\n';
        }

        rep2(i, n+2, 2*n){
            cout << n+1 << ' ' << i << '\n';
        }
        cout << 2*n-1 << ' ' << 2*n << '\n';
    }
    else if(N == 5){
        cout << 1 << ' ' << 3 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << ' ' << 2 << '\n';
        cout << 2 << ' ' << 4 << ' ' << 1 << '\n';
        cout << 4 << ' ' << 5 << ' ' << 1 << '\n';
        cout << 3 << ' ' << 4 << '\n';
        cout << 3 << ' ' << 5 << '\n';
    }
    else{
        int n = (N-1)/2;
        cout << 1 << ' ' << n+1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << ' ' << 2*n-3 << '\n';
        rep2(i, 2, n){
            cout << i << ' ' << n+i << ' ' << 1 << '\n';
        }
        rep2(i, 2, n-2){
            cout << i << ' ' << i+1 << ' ' << n-i << '\n';
        }
        cout << n-1 << ' ' << n << ' ' << 2 << '\n';
        cout << 2*n << ' ' << 2*n+1 << ' ' << 1 << '\n';

        rep2(i, n+2, 2*n+1){
            cout << n+1 << ' ' << i << '\n';
        }
    }
}