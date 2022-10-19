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
    int N, S; cin >> N >> S;

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    vector<int> v(N);
    iota(all(v), 0);
    sort(all(v), [&](int i, int j){
        return a[i] < a[j];
    });

    if(S < a[v.back()]) {cout << "-1\n"; return 0;}
    S -= a[v.back()];

    vector<int> dp(S+1, -1);

    int K = (S>>5)+1;

    vector<unsigned int> A(K, 0);
    A[0] = 1;

    rep(i, N-1){
        int x = a[v[i]]>>5, y = a[v[i]]&31;

        vector<unsigned int> B(K, 0);

        rep(j, K){
            if(j+x < K) B[j+x] |= (A[j]<<y);
            if(j+x+1 < K && y) B[j+x+1] |= (A[j]>>(32-y));
        }

        rep(j, K){
            B[j] &= ~A[j];
            A[j] |= B[j];

            while(B[j] > 0){
                int k = __builtin_ctz(B[j]);
                if((j<<5)+k <= S) dp[(j<<5)+k] = i;
                B[j] &= ~(1U<<k);
            }
        }
    }

    if(S > 0 && dp[S] == -1) {cout << "-1\n"; return 0;}

    vector<bool> used(N, false);
    used[N-1] = true;

    while(S > 0){
        used[dp[S]] = true, S -= a[v[dp[S]]];
    }

    vector<int> c(N, 0);
    vector<int> chi(N, -1);

    int pre = -1;
    rep(i, N){
        if(pre == -1){
            c[v[i]] = a[v[i]];
        }
        else{
            c[v[i]] = a[v[i]]-a[v[i-1]];
            chi[v[i]] = v[i-1];
        }

        if(used[i]) pre = -1;
        else pre = i;
    }

    rep(i, N){
        cout << c[i] << ' ';
        if(chi[i] == -1) cout << "0\n";
        else cout << 1 << ' ' << chi[i]+1 << '\n';
    }
}