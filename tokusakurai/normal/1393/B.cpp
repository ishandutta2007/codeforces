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
    int N;
    cin >> N;
    int cnt[1<<18], num[1<<18];
    fill(cnt, cnt+(1<<18), 0), fill(num, num+(1<<18), 0);
    rep(i, N){
        int a; cin >> a;
        cnt[a]++;
    }
    rep(i, 1<<18) num[cnt[i]]++;
    int Q;
    cin >> Q;
    int sum = N;
    while(Q--){
        char c; int x;
        cin >> c >> x;
        num[cnt[x]]--;
        if(c == '+') cnt[x]++, sum++;
        else cnt[x]--, sum--;
        num[cnt[x]]++;
        int now = 0;
        rep(i, 8) now += i*num[i];
        if(now < sum) {cout << "YES" << endl; continue;}
        int s[8];
        s[2] = num[2]+num[3], s[4] = num[4]+num[5], s[6] = num[6]+num[7];
        if(s[6] && s[2]+s[4]) {cout << "YES" << endl; continue;}
        if(s[4]+s[6] >= 2) {cout << "YES" << endl; continue;}
        if(s[4] && s[2] >= 2) {cout << "YES" << endl; continue;}
        cout << "NO" << endl;
    }
}