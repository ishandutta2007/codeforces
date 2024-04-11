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

template<typename T>
struct Sparse_Table{
    using F = function<T(T, T)>;
    const int n;
    vector<vector<T>> st;
    vector<int> lookup;
    const F f;
    const T e;

    Sparse_Table(const vector<T> &table, const F &f, const T &e) : n((int)table.size()), f(f), e(e){
        int log_n = 32-__builtin_popcount(n);
        st.assign(log_n, vector<T>(n));
        for(int i = 0; i < n; i++) st[0][i] = table[i];
        for(int j = 0; j < log_n-1; j++){
            for(int i = 0; i < n; i++){
                if(i+(1<<j) < n) st[j+1][i] = f(st[j][i], st[j][i+(1<<j)]);
                else st[j+1][i] = st[j][i];
            }
        }
        lookup.assign(n+1, -1);
        for(int i = 1; i <= n; i++) lookup[i] = lookup[i/2]+1;
    }

    T query(int l, int r) const{
        if(l >= r) return e;
        int k = lookup[r-l];
        return f(st[k][l], st[k][r-(1<<k)]);
    }

    T operator [] (int i) const {return st[0][i];}
};

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<ll> a(N);
        rep(i, N) cin >> a[i];
        if(N == 1){
            cout << "1\n";
            continue;
        }

        vector<ll> b(N-1);
        rep(i, N-1) b[i] = abs(a[i+1]-a[i]);

        auto f = [](ll a, ll b) {return gcd(a, b);};
        Sparse_Table<ll> st(b, f, 0);

        int ans = 0;
        int ptr = 0;
        rep(i, N-1){
            chmax(ptr, i);
            ll x = st.query(i, ptr);
            while(ptr < N-1){
                ll tmp = gcd(x, b[ptr]);
                if(tmp >= 2){
                    x = tmp, ptr++;
                }
                else{
                    break;
                }
            }
            chmax(ans, ptr-i);
        }

        cout << ans+1 << '\n';
    }
}