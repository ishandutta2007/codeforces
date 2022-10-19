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
    ll N; cin >> N;

    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    vector<ll> A(4, 0);
    rep(i, N){
        if((x[i]+y[i])%4 == 0){
            if(x[i]%4 == 0) A[0]++;
            else A[1]++;
        }
        else{
            if(x[i]%4 == 0) A[2]++;
            else A[3]++;
        }
    }

    ll ans = 0;
    /*
    ans += (A1*(A1-1)*(A1-2)/6);
    ans += (A2*(A2-1)*(A2-2)/6);
    ans += (A3*(A3-1)*(A3-2)/6);
    ans += (A4*(A4-1)*(A4-2)/6);
    ans += (A1*(A1-1)/2)*A3 + (A3*(A3-1)/2)*A1;
    ans += (A2*(A2-1)/2)*A4 + (A4*(A4-1)/2)*A2;
    ans += (A1*(A1-1)/2)*A4 + (A4*(A4-1)/2)*A1;
    ans += (A2*(A2-1)/2)*A3 + (A3*(A3-1)/2)*A2;
    */

    rep(i, 4){
        ans += (A[i]*(A[i]-1)*(A[i]-2))/6;
        rep(j, 4){
            if(i == j) continue;
            ans += ((A[i]*(A[i]-1))/2)*A[j];
        }
    }

    cout << ans << '\n';
}