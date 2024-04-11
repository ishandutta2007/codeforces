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
        int N, K; cin >> N >> K;
        string S; cin >> S;

        vector<int> a(N), b(N);
        rep(i, N){
            a[i] = S[i]-'a';
            b[i] = (a[i] == 0? 0 : a[i] == K-1? 0 : a[i]-1);
        }

        vector<int> ans;
        int i = 0, c = -1;

        while(i < N){
            if(c == -1){
                int x = inf, y = inf, z = inf;
                x = b[i];
                if(i+1 < N) y = b[i+1];
                if(i+2 < N) z = a[i+2];

                if(x <= y && x <= z) c = x, i += 1;
                else if(y <= x && y <= z) ans.eb(y), c = (y == a[i+1]? b[i] : a[i]), i += 2;
                else ans.eb(z), ans.eb(x), c = a[i+1], i += 3;
            }
            else{
                int x = inf, y = inf, z = inf;
                x = c;
                y = a[i];
                if(i+1 < N) z = a[i+1];

                if(x <= y && x <= z) ans.eb(x), c = -1;
                else if(y <= x && y <= z) ans.eb(y), c = x, i += 1;
                else ans.eb(z), ans.eb(x), c = y, i += 2;
            }
        }

        if(c != -1) ans.eb(c);

        for(auto &e: ans) cout << char('a'+e);
        cout << '\n';
    }
}