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

        vector<int> a(N), b(N), c(M);
        rep(i, N) {cin >> a[i]; a[i]--;}
        rep(i, N) {cin >> b[i]; b[i]--;}
        rep(i, M) {cin >> c[i]; c[i]--;}

        vector<vector<int>> ids(N);
        int id = -1;

        rep(i, N){
            if(b[i] == c[M-1]) id = i;
            if(a[i] != b[i]) ids[b[i]].eb(i);
        }

        if(id == -1) {cout << "NO\n"; continue;}

        vector<int> ans(M);
        vector<int> ptr(N, 0);

        rep3(i, M-1, 0){
            if(ptr[c[i]] >= sz(ids[c[i]])) ans[i] = id;
            else{
                int x = ids[c[i]][ptr[c[i]]++];
                ans[i] = x, id = x;
            }
        }

        bool flag = true;
        rep(i, N){
            if(ptr[i] < sz(ids[i])) flag = false;
        }

        if(flag){
            cout << "YES\n";
            rep(i, M){
                cout << ans[i]+1 << (i == M-1? '\n' : ' ');
            }
        }
        else cout << "NO\n";
    }
}