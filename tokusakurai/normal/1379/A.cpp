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
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int T;
    cin >> T;
    string a = "abacaba";
    while(T--){
        int N; string S;
        cin >> N >> S;
        vector<int> v1, v2;
        rep(i, N-6){
            bool flag1 = true, flag2 = true;
            rep(j, 7){
                if(S[i+j] != a[j]){
                    flag1 = false;
                    if(S[i+j] != '?') flag2 = false;
                }
            }
            if(flag1) v1.pb(i);
            elif(flag2) v2.pb(i);
        }
        if(sz(v1) >= 2) cout << "No" << endl;
        elif(sz(v1) == 1){
            cout << "Yes" << endl;
            rep(i, N) if(S[i] == '?') S[i] = 'z';
            cout << S << endl;
        }
        else{
            int st = -1;
            string tmp;
            for(auto &e: v2){
                tmp = S;
                rep(i, 7) if(tmp[e+i] == '?') tmp[e+i] = a[i];
                int cnt = 0;
                rep(i, N-6){
                    bool flag = true;
                    rep(j, 7){
                        if(tmp[i+j] != a[j]) flag = false;
                    }
                    if(flag) cnt++;
                }
                if(cnt == 1) st = e;
            }
            if(st == -1) cout << "No" << endl;
            else{
                cout << "Yes" << endl;
                rep(i, 7) S[st+i] = a[i];
                rep(i, N) if(S[i] == '?') S[i] = 'z';
                cout << S << endl;
            }
        }
    }
}