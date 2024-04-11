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

int f(int x){
    int ret = 0;
    while(x) ret += x%10, x /= 10;
    return ret;
}

int main(){
    /*
    int N;
    cin >> N;
    rep2(i, 1, N){
        vector<bool> table(i, false);
        rep(j, 21-i){
            int s = 0;
            rep(k, i) s += f(j+k);
            table[s%i] = true;
        }
        rep(j, i) cout << table[j] << ' '; cout << '\n';
    }
    */

    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        K++;

        int rem = inf; //
        vector<int> res(100, 0);
        bool up = false;
        rep(i, 10){
            int s = 0;
            rep(j, K) s += f(i+j);
            if(N >= s && (N-s)%K == 0){
                if(chmin(rem, (N-s)/K)){
                    res[0] = i%10;
                    if(i+K-1 >= 10) up = true;
                    else up = false;
                }
            }
        }
        if(rem == inf) {cout << -1 << '\n'; continue;}
        
        rep2(i, 1, 99){
            if(rem == 0) break;
            int k = min(rem, 9);
            if(i == 1 && up) chmin(k, 8);
            res[i] += k, rem -= k;
        }
        
        while(sz(res) >= 2 && res.back() == 0) res.pop_back();
        reverse(all(res));
        each(e, res) cout << e; cout << '\n';
    }
}