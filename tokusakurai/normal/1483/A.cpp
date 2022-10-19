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
        int N, M; cin >> N >> M;

        vector<int> cnt(N, 0);
        vector<vector<int>> solo(N);

        vector<vector<int>> a(M);

        rep(i, M){
            int k; cin >> k;
            rep(j, k){
                int u; cin >> u; u--;
                cnt[u]++;
                if(k == 1) solo[u].eb(i);
                a[i].eb(u);
            }
        }

        vector<int> ans(M, -1);

        bool flag = true;

        int id = -1, rem = 0;

        rep(i, N){
            if(sz(solo[i]) > (M+1)/2) {flag = false; break;}

            if(cnt[i] > (M+1)/2){
                each(e, solo[i]) ans[e] = i;
                id = i, rem = (M+1)/2-sz(solo[i]);
                break;
            }
        }

        //cout << id << ' ' << rem << '\n';

        if(!flag) {cout << "NO\n"; continue;}

        rep(i, M){
            if(ans[i] != -1) continue;

            bool tmp = false;
            int use = -1;

            each(e, a[i]){
                if(e == id && rem > 0) tmp = true;
                if(e != id) use = e;
            }

            if(tmp) ans[i] = id, rem--;
            else ans[i] = use;
        }

        cout << "YES\n";

        rep(i, M) cout << ans[i]+1 << (i == M-1? '\n' : ' ');
    }
}