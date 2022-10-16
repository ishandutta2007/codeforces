#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e9 + 7;
// const int INF = 100;

// min st
void st_add(vi &st, vi &lazy, int pos, int tl, int tr, int left, int right, int val){
    if(tr < left || right < tl) return;
    if(left <= tl && tr <= right){
        debug(tl, tr, pos, val);
        lazy[pos] += val;
        return;
    }
    // propogate
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;

    st_add(st, lazy, 2 * pos, tl, tl + (tr - tl) / 2, left, right, val);
    st_add(st, lazy, 2 * pos + 1, tl + (tr - tl) / 2 + 1, tr, left, right, val);

    st[pos] = min(st[2 * pos] + lazy[2 * pos], st[2 * pos + 1] + lazy[2 * pos + 1]);
}

int st_min(vi &st, vi &lazy, int pos, int tl, int tr, int left, int right){
    if(tr < left || right < tl) return INF;
    if(left <= tl && tr <= right){
        return st[pos] + lazy[pos];
    }
    // propogate
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;

    int x = st_min(st, lazy, 2 * pos, tl, tl + (tr - tl) / 2, left, right);
    int y = st_min(st, lazy, 2 * pos + 1, tl + (tr - tl) / 2 + 1, tr, left, right);

    st[pos] = min(st[2 * pos] + lazy[2 * pos], st[2 * pos + 1] + lazy[2 * pos + 1]);

    return min(x, y);
}

void st_set(vi &st, vi &lazy, int n, int pos, int val){
    int cur = st_min(st, lazy, 1, 0, n-1, pos, pos);
    debug(val - cur);
    st_add(st, lazy, 1, 0, n-1, pos, pos, val - cur);
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    // dp[i][j]: after index i, j slice operations
    vvi dp(n, vi(k, INF));
    // build j=0
    vi last(n + 1, -1);
    dp[0][0] = 0;
    last[v[0]] = 0;
    for(int i = 1; i < n; i++){
        if(last[v[i]] == -1){
            dp[i][0] = dp[i-1][0];
        }
        else{
            dp[i][0] = dp[i-1][0] + i - last[v[i]];
        }
        last[v[i]] = i;
    }
    for(int j = 1; j < k; j++){
        vi st(4 * n, INF);
        vi lazy(4 * n);

        vi last(n + 1, -1);
        last[v[0]] = 0;
        
        st_set(st, lazy, n, 0, dp[0][j-1]);
        for(int i = 1; i < n; i++){
            if(last[v[i]] >= 0){
                debug("add", 0, last[v[i]] - 1, last[v[i]] - 1);
                st_add(st, lazy, 1, 0, n-1, 0, last[v[i]] - 1, i - last[v[i]]);
            }

            dp[i][j] = st_min(st, lazy, 1, 0, n-1, 0, i-1);
            st_set(st, lazy, n, i, dp[i][j-1]);

            last[v[i]] = i;
        }
    }
    debug(dp);
    cout << dp[n-1][k-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}