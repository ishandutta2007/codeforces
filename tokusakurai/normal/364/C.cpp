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

int K;

vector<int> ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 31};
vector<int> ok;

void dfs(int x, int i, int k){
    if(i == k){
        ok.eb(x);
        return;
    }
    while(x <= 2*K*K){
        dfs(x, i+1, k);
        x *= ps[i];
    }
}

bool solve(int k){
    ok.clear();
    dfs(1, 0, k);
    
    if(sz(ok) >= K){
        //each(e, ok) cout << e << ' '; cout << '\n';
        vector<vector<int>> ids(1<<k);
        each(e, ok){
            int s = 0;
            rep(i, k){
                if(e%ps[i] == 0) s |= 1<<i;
            }
            ids[s].eb(e);
        }

        vector<int> v(1<<k, 0);
        iota(all(v), 0);
        sort(all(v), [](int i, int j){
            int a = __builtin_popcount(i), b = __builtin_popcount(j);
            if(a != b) return a > b;
            else return i > j;
        });

        vector<int> cnt(k, 0);
        int R = K;
        vector<int> ans;

        each(e, v){
            int T = min(R, sz(ids[e]));
            R -= T;
            rep(i, T){
                ans.eb(ids[e][i]);
            }

            rep(i, k){
                if((e>>i)&1) cnt[i] += T;
            }
        }

        bool flag = true;
        rep(i, k){
            if(cnt[i] < (K+1)/2) flag = false; 
        }

        if(flag){
            //cout << sz(ans) << '\n';
            sort(all(ans));
            rep(i, K) cout << ans[i] << (i == K-1? '\n' : ' ');
            return true;
        }
    }
    
    return false;
}

int main(){
    cin >> K;

    rep2(i, 1, 10){
        if(solve(i)) break;
    }
}