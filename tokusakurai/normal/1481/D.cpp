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

void solve(){
    int N, M; cin >> N >> M;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    rep(i, N){
        rep(j, i){
            if(S[i][j] == S[j][i]){
                cout << "YES\n";
                rep(k, M+1){
                    cout << (k&1? i+1 : j+1) << (k == M? '\n' : ' ');
                }
                return;
            }
        }
    }

    if(M&1){
        cout << "YES\n";
        rep(i, M+1){
            cout << (i&1? 2 : 1) << (i == M? '\n' : ' ');
        }
        return;
    }

    if(N == 2) {cout << "NO\n"; return;}

    int a, b, c;

    rep(i, 3){
        int j = (i+1)%3, k = (j+1)%3;

        if(S[i][j] == S[j][k]) a = i, b = j, c = k;
    }

    if(M%4 == 0){
        cout << "YES\n";
        rep(i, M/4){
            cout << b+1 << ' ' << a+1 << ' ' << b+1 << ' ' << c+1 << ' ';
        }
        cout << b+1 << '\n';
    }
    else{
        cout << "YES\n";
        rep(i, M/4){
            cout << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << b+1 << ' ';
        }
        cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
    }
}

int main(){
    int T; cin >> T;

    while(T--){
        solve();
    }
}