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
vector<T> divisors(const T &n){
    vector<T> ret;
    for(T i = 1; i*i <= n; i++){
        if(n%i == 0){
            ret.pb(i);
            if(i*i != n) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

template<typename T>
vector<pair<T, int>> prime_factor(T n){
    vector<pair<T, int>> ret;
    for(T i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0) cnt++, n /= i;
        if(cnt > 0) ret.emplace_back(i, cnt);
    }
    if(n > 1) ret.emplace_back(n, 1);
    return ret;
}

template<typename T>
bool is_prime(const T &n){
    if(n == 1) return false;
    for(T i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

vector<bool> Eratosthenes(const int &n){
    vector<bool> ret(n+1, true);
    if(n >= 0) ret[0] = false;
    if(n >= 1) ret[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!ret[i]) continue;
        for(int j = i+i; j <= n; j += i) ret[j] = false;
    }
    return ret;
}

vector<int> Eratosthenes2(const int &n){
    vector<int> ret(n+1);
    iota(begin(ret), end(ret), 0);
    if(n >= 0) ret[0] = -1;
    if(n >= 1) ret[1] = -1;
    for(int i = 2; i*i <= n; i++){
        if(ret[i] < i) continue;
        for(int j = i+i; j <= n; j += i) ret[j] = min(ret[j], i);
    }
    return ret;
}

int main(){
    int T; cin >> T;

    vector<int> p = Eratosthenes2(10000000);

    while(T--){
        int N, K; cin >> N >> K;

        vector<int> a(N);

        map<int, int> mp;

        rep(i, N){
            cin >> a[i];
            map<int, int> tmp;

            while(a[i] > 1){
                int x = p[a[i]];
                tmp[x]++, a[i] /= x;
            }

            each(e, tmp){
                if(e.second%2 == 1) a[i] *= e.first;
            }

            mp[a[i]]++;
        }

        int n = 0;
        each(e, mp) e.second = n++;

        rep(i, N) a[i] = mp[a[i]];

        vector<int> last(n, -1);
        vector<int> pre(N, -1);

        rep(i, N){
            pre[i] = last[a[i]];
            last[a[i]] = i;
        }

        vector<vector<int>> dp(N+1, vector<int>(K+1, inf));

        fill(all(dp[0]), 0);
        set<int> s;

        rep(i, N){
            s.emplace(pre[i]+1);

            vector<int> check;
            for(auto it = s.rbegin(); it != s.rend(); it++){
                check.eb(*it);
                if(sz(check) > K) break;
            }

            rep(j, sz(check)){
                rep(k, K+1){
                    if(j+k <= K) chmin(dp[i+1][j+k], dp[check[j]][k]+1);
                }
            }
        }

        cout << dp[N][K] << '\n';
    }
}