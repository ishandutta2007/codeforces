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

int lx, rx, ly, ry;

bool in(int x, int y){
    return (lx <= x && x <= rx && ly <= y && y <= ry);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y;
        cin >> x >> y >> lx >> ly >> rx >> ry;
        
        int tx = x-a+b, ty = y-c+d;
        if(!in(tx, ty)) {cout << "No\n"; continue;}
        
        bool ans = true;
        if(a == b && a != 0 && x == lx && x == rx) ans = false;
        if(c == d && c != 0 && y == ly && y == ry) ans = false;

        cout << (ans? "Yes\n" : "No\n");
    }
}