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
        int N; ll M; cin >> N >> M;

        vector<ll> x(N);
        rep(i, N) cin >> x[i];
        vector<char> c(N), d(N);
        rep(i, N) cin >> d[i];

        vector<int> v(N);
        iota(all(v), 0);
        sort(all(v), [&](int i, int j){
            return x[i] < x[j];
        });

        sort(all(x));
        rep(i, N) c[i] = d[v[i]];

        vector<int> id(N);
        rep(i, N) id[v[i]] = i;

        vector<ll> ans(N, -1);

        rep(t, 2){
            deque<int> que;
            rep(i, N){
                if(x[i]%2 != t) continue;

                if(c[i] == 'R'){
                    que.emplace_back(i);
                }
                else{
                    if(!empty(que) && c[que.back()] == 'R'){
                        int j = que.back(); que.pop_back();
                        ans[j] = ans[i] = (x[i]-x[j])/2;
                    }
                    else{
                        que.emplace_back(i);
                    }
                }
            }

            while(sz(que) >= 2 && c[que[0]] == 'L' && c[que[1]] == 'L'){
                int i = que[0], j = que[1];
                que.pop_front(), que.pop_front();
                ans[i] = ans[j] = (x[i]+x[j])/2;
            }
            while(sz(que) >= 2 && c[que[sz(que)-1]] == 'R' && c[que[sz(que)-2]] == 'R'){
                int i = que[sz(que)-1], j = que[sz(que)-2];
                que.pop_back(), que.pop_back();
                ans[i] = ans[j] = M-(x[i]+x[j])/2;
            }

            if(sz(que) >= 2){
                int i = que[0], j = que[1];
                que.pop_front(), que.pop_front();
                ans[i] = ans[j] = M-(x[j]-x[i])/2;
            }
        }

        rep(i, N) cout << ans[id[i]] << (i == N-1? '\n' : ' ');
    }
}