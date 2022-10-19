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
    int N; cin >> N;

    queue<pii> p, q;
    rep(i, N){
        rep(j, N){
            if(i%2 == j%2) p.emplace(i, j);
            else q.emplace(i, j);
        }
    }

    bool flag = false;

    rep(i, N*N){
        int k; cin >> k;
    
        if(!flag){
            if(k != 1){
                auto [x, y] = p.front(); p.pop();
                cout << 1 << ' ' << x+1 << ' ' << y+1 << endl;
            }
            else{
                auto [x, y] = q.front(); q.pop();
                cout << 2 << ' ' << x+1 << ' ' << y+1 << endl;
            }
            if(p.empty() || q.empty()) flag = true;
        }
        else{
            if(p.empty()){
                int j = (k == 2? 3 : 2);
                auto [x, y] = q.front(); q.pop();
                cout << j << ' ' << x+1 << ' ' << y+1 << endl;
            }
            else{
                int j = (k == 1? 3 : 1);
                auto [x, y] = p.front(); p.pop();
                cout << j << ' ' << x+1 << ' ' << y+1 << endl;
            }
        }
    }
}