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
    int A, B, K; cin >> A >> B >> K;

    if(K == 0){
        cout << "Yes\n";
        rep(i, 2){
            cout << string(B, '1')+string(A, '0') << '\n';
        }
        return 0;
    }

    if(A == 0 || B == 1) {cout << "No\n"; return 0;}
    if(K >= A+B-1) {cout << "No\n"; return 0;}

    string S(A+B, '0'), T(A+B, '0');
    S[0] = '1', T[0] = '1';
    S[1] = '1', T[K+1] = '1';

    int rem = B-2;

    rep(i, A+B){
        if(S[i] == '0' && T[i] == '0' && rem > 0){
            S[i] = '1', T[i] = '1', rem--;
        }
    }

    cout << "Yes\n" << S << '\n' << T << '\n';
}