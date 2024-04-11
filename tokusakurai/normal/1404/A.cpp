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
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int T;
    cin >> T;
    vector<string> ans;
    while(T--){
        int N, K;
        string S;
        cin >> N >> K >> S;
        int res[K];
        fill(res, res+K, -1);
        bool flag = false;
        rep(i, N){
            if(S[i] == '?') continue;
            int x = S[i]-'0';
            if(res[i%K] == (x^1)) flag = true;
            else res[i%K] = x;
        }
        if(flag) {ans.pb("NO"); continue;}
        int cnt1 = 0, cnt2 = 0;
        rep(i, K){
            if(res[i] == 0) cnt1++;
            if(res[i] == 1) cnt2++;
        }
        if(cnt1 <= K/2 && cnt2 <= K/2) ans.pb("YES");
        else ans.pb("NO");
    }
    for(auto &e: ans) cout << e << endl;
}