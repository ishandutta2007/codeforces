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
    int T; cin >> T;

    while(T--){
        string S; cin >> S;

        int N = sz(S);

        vector<vector<int>> ids(26);

        rep(i, N){
            int x = S[i]-'a';
            ids[x].eb(i);
        }
        vector<bool> used(26, false);
        rep(i, 26){
            if(ids[i].empty()) used[i] = true;
        }

        int pre = -1;
        string ans;

        while(true){
            int p = inf;
            rep(i, 26){
                if(!used[i]) chmin(p, ids[i].back());
            }
            if(p == inf) break;

            rep3(i, 25, 0){
                if(used[i]) continue;
                if(*upper_bound(all(ids[i]), pre) <= p){
                    ans += char('a'+i);
                    pre = *upper_bound(all(ids[i]), pre);
                    used[i] = true;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}