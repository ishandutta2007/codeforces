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
    int N, M; cin >> N >> M;

    vector<int> t(M), a(M), b(M), c(M);
    vector<int> S(N, 0), A(N, inf);

    rep(i, M){
        cin >> t[i] >> a[i] >> b[i] >> c[i]; a[i]--, b[i]--;
        if(t[i] == 1){
            rep2(j, a[i], b[i]) S[j] += c[i];
        }
        else{
            rep2(j, a[i], b[i]) chmin(A[j], c[i]-S[j]);
        }
    }
    
    rep(i, N){
        if(A[i] == inf) A[i] = 0;
    }
    vector<int> B = A;
    bool flag = true;

    rep(i, M){
        if(t[i] == 1){
            rep2(j, a[i], b[i]) B[j] += c[i];
        }
        else{
            int m = -inf;
            rep2(j, a[i], b[i]) chmax(m, B[j]);
            if(m != c[i]) flag = false;
        }
    }

    if(!flag){
        cout << "NO\n";
        //rep(i, N) cout << A[i] << (i == N-1? '\n' : ' ');
    }
    else{
        cout << "YES\n";
        rep(i, N) cout << A[i] << (i == N-1? '\n' : ' ');
    }
}