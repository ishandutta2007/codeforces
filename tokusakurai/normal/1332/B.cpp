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
    int T;
    cin >> T;
    vector<int> ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while(T--){
        int N;
        cin >> N;
        vector<int> ans(N);
        rep(i, N){
            int x; cin >> x;
            rep(j, sz(ps)){
                if(x%ps[j] == 0) ans[i] = j;
            }
        }
        
        map<int, int> mp;
        each(e, ans) mp[e]++;
        int n = 0;
        each(e, mp) e.second = n++;

        cout << n << '\n';
        each(e, ans) cout << mp[e]+1 << ' '; cout << '\n';
    }
}