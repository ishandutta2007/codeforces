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

const int MAXN = 1e5 + 5;
const int LOGN = 17;
// const int MAXN = 10;
const int INF = 1e9 + 7;

vi lp(MAXN);
vi pr;

void preprocess(){
    for (int i=2; i<MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<MAXN; ++j){
            lp[i * pr[j]] = pr[j];
        }
    }
    // debug(lp, pr);
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vi last_occ(MAXN, n);
    vi max_idx(n);
    for(int i = n-1; i >= 0; i--){
        set<int> factors;
        int cur = v[i];
        while(cur > 1){
            factors.insert(lp[cur]);
            cur /= lp[cur];
        }
        int maxi = i == n-1 ? n : max_idx[i+1];
        for(int j : factors){
            maxi = min(maxi, last_occ[j]);
            last_occ[j] = i;
        }
        max_idx[i] = maxi;
    }
    debug(max_idx);

    // binary lifting of max_idx
    vvi lift(n+1, vi(LOGN+1));
    for(int i = 0; i < n; i++){
        lift[i][0] = max_idx[i];
    }
    lift[n][0] = n;
    for(int level = 1; level <= LOGN; level++){
        for(int i = 0; i <= n; i++){
            lift[i][level] = lift[lift[i][level-1]][level-1];
        }
    }
    debug(lift);

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        int target = r+1;
        int ans = INF, cur_times = 0, pos = l;
        for(int level = LOGN; level >= 0; level--){
            int lifted = lift[pos][level];
            if(lifted >= target){
                ans = min(ans, cur_times + (1 << level));
            }
            else{
                cur_times += 1 << level;
                pos = lifted;
            }
        }
        cout << ans << endl;
    }
}

int main(){
    preprocess();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}