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
        int N, P; cin >> N >> P;
        vector<vector<bool>> es(N, vector<bool>(N, false));

        rep(i, N){
            int j = (i+1)%N, k = (j+1)%N;
            cout << i+1 << ' ' << j+1 << '\n';
            cout << i+1 << ' ' << k+1 << '\n';
            es[i][j] = true, es[j][i] = true;
            es[i][k] = true, es[k][i] = true;
        }
        /*
        vector<int> ps = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        int d = -1;
        each(e, ps){
            if(e < N && N%e != 0){
                d = e;
                break;
            }
        }

        rep(i, N){
            int j = i*d%N, k = (i+1)*d%N;
            cout << j+1 << ' ' << k+1 << '\n';
            es[j][k] = true, es[k][j] = true;
        }
        */
        rep(i, N){
            rep(j, i){
                if(es[j][i] || P == 0) continue;
                cout << j+1 << ' ' << i+1 << '\n';
                P--;
            }
        }
    }
}