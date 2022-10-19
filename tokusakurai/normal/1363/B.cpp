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

int main(){
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        int N = sz(S);
        int cnt1[N+1], cnt2[N+1];
        cnt1[0] = cnt2[0] = 0;
        rep(i, N){
            cnt1[i+1] = cnt1[i], cnt2[i+1] = cnt2[i];
            if(S[i] == '0') cnt2[i+1]++;
            else cnt1[i+1]++;
        }
        int M = 0;
        rep(i, N+1){
            chmax(M, i-cnt2[i]+N-i-(cnt1[N]-cnt1[i]));
            chmax(M, i-cnt1[i]+N-i-(cnt2[N]-cnt2[i]));
        }
        cout << N-M << endl;
    }
}