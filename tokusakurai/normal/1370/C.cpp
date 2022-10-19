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
    string a = "Ashishgup", b = "FastestFinger";
    int T;
    cin >> T;
    rep(t, T){
        int N;
        cin >> N;
        if(N == 1) {cout << b << endl; continue;}
        if(N%2 == 1 || N == 2) {cout << a << endl; continue;}
        int cnt = 0;
        while(N%2 == 0) N /= 2, cnt++;
        if(N == 1) {cout << b << endl; continue;}
        if(cnt >= 2) {cout << a << endl; continue;}
        bool flag = false;
        for(int i = 2; i*i <= N; i++){
            if(N%i == 0) flag = true;
        }
        if(flag) cout << a << endl;
        else cout << b << endl;
    }
}