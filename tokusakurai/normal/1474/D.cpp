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
    int T; cin >> T;
    
    while(T--){
        int N; cin >> N;
        vector<ll> a(N);
        rep(i, N) cin >> a[i];

        vector<ll> L(N+1, 0), R(N+1, 0);
        rep(i, N){
            if(i%2 == 0) L[i+1] = L[i]+a[i];
            else L[i+1] = L[i]-a[i];
        }
        rep3(i, N-1, 0){
            if(i%2 == (N-1)%2) R[i] = R[i+1]+a[i];
            else R[i] = R[i+1]-a[i];
        }

        int r = 0;
        while(r < N){
            if(r%2 == 0){
                if(L[r+1] >= 0) r++;
                else break;
            }
            else{
                if(L[r+1] <= 0) r++;
                else break;
            }
        }

        int l = N;
        while(l > 0){
            if(l%2 == N%2){
                if(R[l-1] >= 0) l--;
                else break;
            }
            else{
                if(R[l-1] <= 0) l--;
                else break;
            }
        }

        ll x = 0, y = 0;
        rep(i, N){
            if(i%2 == 0) x += a[i];
            else y += a[i];
        }

        if(r == N && x == y) {cout << "YES\n"; continue;}

        bool flag = false;
        rep(i, N-1){
            ll X = x, Y = y, A = L[i+1], B = L[i+2];
            if(i%2 == 0){
                X += a[i+1]-a[i], Y += a[i]-a[i+1];
                A += a[i+1]-a[i], B += 2*(a[i+1]-a[i]);
                if(A < 0 || B > 0) continue;
            }
            else{
                Y += a[i+1]-a[i], X += a[i]-a[i+1];
                A += a[i]-a[i+1], B += 2*(a[i]-a[i+1]);
                if(A > 0 || B < 0) continue;
            }
            if(X != Y) continue;

            if(r >= i && l <= i+2) flag = true;
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}