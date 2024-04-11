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
    while(T--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        bool flag1 = true, flag2 = true;
        rep(i, N){
            if(S[i] == '<') flag1 = false;
            if(S[i] == '>') flag2 = false;
        }
        int ans = 0;
        rep(i, N){
            int j = (i+N-1)%N;
            if(S[i] == '-' || S[j] == '-') ans++;
            else{
                if(S[i] == '>' && flag1) ans++;
                elif(S[j] == '<' && flag2) ans++; 
            }
        }
        cout << ans << endl;
    }
}