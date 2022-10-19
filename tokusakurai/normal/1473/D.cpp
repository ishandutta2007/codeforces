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
    while(T--){
        int N, Q;
        cin >> N >> Q;
        string S;
        cin >> S;

        vector<int> c(N+1, 0);
        vector<int> ml(N+1, 0), mr(N+1, 0), Ml(N+1, 0), Mr(N+1, 0);
        rep(i, N){
            c[i+1] = c[i], ml[i+1] = ml[i], Ml[i+1] = Ml[i];
            if(S[i] == '+'){
                c[i+1]++;
                chmax(Ml[i+1], c[i+1]);
            }
            else{
                c[i+1]--;
                chmin(ml[i+1], c[i+1]);
            }
        }

        rep3(i, N-1, 0){
            if(S[i] == '+'){
                chmax(Mr[i], Mr[i+1]+1);
                chmin(mr[i], mr[i+1]+1);
            }
            else{
                chmax(Mr[i], Mr[i+1]-1);
                chmin(mr[i], mr[i+1]-1);
            }
        }

        while(Q--){
            int L, R;
            cin >> L >> R;
            L--;
            int M = max(Ml[L], c[L]+Mr[R]);
            int m = min(ml[L], c[L]+mr[R]);
            cout << M-m+1 << '\n';
        }
    }
}