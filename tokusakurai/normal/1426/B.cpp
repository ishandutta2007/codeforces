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
        int N, M;
        cin >> N >> M;
        bool flag1 = false, flag2 = false;
        int p[N][2][2];
        rep(i, N){
            rep(j, 2) rep(k, 2) cin >> p[i][j][k];
        }
        if(M&1) {cout << "NO" << endl; continue;}
        rep(i, N){
            if(p[i][0][1] == p[i][1][0]) flag1 = true;
        }
        rep(i, N){
            rep(j, N){
                bool tmp = true;
                rep(k, 2) rep(l, 2){
                    if((k^l) && p[i][k][l] != p[j][k^1][l^1]) tmp = false;
                    if(!(k^l) && p[i][k][l] != p[j][k][l]) tmp = false;
                }
                if(tmp) flag2 = true;
            }
        }
        if(flag1 && flag2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}