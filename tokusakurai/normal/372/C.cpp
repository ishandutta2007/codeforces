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
    ll N, M, D; cin >> N >> M >> D;

    vector<ll> dp(N, 0);
    ll pre = -inf;
    
    rep(i, M){
        vector<ll> tmp(N, 0);
        ll a, b, t; cin >> a >> b >> t; a--;

        ll d = D*(t-pre);
        int ptr = 0;
        deque<int> que;

        rep(j, N){
            while(ptr <= min(N-1, j+d)){
                while(!que.empty() && dp[que.back()] <= dp[ptr]){
                    que.pop_back();
                }
                que.push_back(ptr++);
            }

            tmp[j] = b-abs(a-j)+dp[que.front()];

            if(que.front() == j-d) que.pop_front();
            pre = t;
        }

        swap(dp, tmp);
    }

    cout << *max_element(all(dp)) << '\n';
}