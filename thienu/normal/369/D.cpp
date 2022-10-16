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

enum prob{
    ALWAYS,
    NEVER,
    SOMETIMES
};

int INF = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector<prob> v(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        switch(x){
            case 0:
            v[i] = NEVER;
            break;
            case 100:
            v[i] = ALWAYS;
            break;
            default:
            v[i] = SOMETIMES;
            break;
        }
    }
    vi suf_has_never(n+1);
    vi suf_has_always(n+1);
    vi suf_has_killable(n+1);
    for(int i = n-1; i >= 0; i--){
        suf_has_never[i] = suf_has_never[i+1] || v[i] == NEVER;
        suf_has_always[i] = suf_has_always[i+1] || v[i] == ALWAYS;
        suf_has_killable[i] = suf_has_killable[i+1] || v[i] != NEVER;
    }
    debug(suf_has_never, suf_has_always, suf_has_killable);
    vvi dp(n, vi(n, INF));
    dp[0][1] = 0;
    int ans = 1;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(b <= a || (a == 0 && b == 1)) continue;
            if(a + 1 == b){
                for(int c = 0; c < a; c++){
                    if(v[c] != ALWAYS && suf_has_killable[a]){
                        dp[a][b] = min(dp[a][b], dp[c][a] + 1);
                    }
                }
                for(int c = 0; c < a-1; c++){
                    if(v[c] != NEVER && suf_has_killable[a-1]){
                        dp[a][b] = min(dp[a][b], dp[c][a-1] + 1);
                    }
                }
            }
            else{
                if(v[a] != NEVER && !suf_has_always[b-1]){
                    dp[a][b] = min(dp[a][b], dp[a][b-1] + 1);
                }
            }
            if(dp[a][b] <= k) ans++;
        }
    }
    debug(dp, ans);
    // one alive, not end
    for(int a = 0; a < n-1; a++){
        if(dp[a][n-1] < k && v[a] != NEVER && v[n-1] != ALWAYS){
            ans++;
        }
    }
    // one alive, end, case 1
    bool good = false;
    for(int a = 0; a < n-2; a++){
        if(dp[a][n-2] < k && v[a] != NEVER && v[n-2] != NEVER){
            good = true;
        }
    }
    // case 2
    for(int a = 0; a < n-1; a++){
        if(dp[a][n-1] < k && v[a] != ALWAYS && v[n-1] != NEVER){
            good = true;
        }
    }
    if(good) ans++;

    // zero alive
    for(int a = 0; a < n-1; a++){
        if(dp[a][n-1] < k && v[a] != NEVER && v[n-1] != NEVER){
            ans++;
            break;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}