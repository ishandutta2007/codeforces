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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vi cnt1(26), cnt2(26);
    for(char c : s) cnt1[c-'a']++;
    for(char c : t) cnt2[c-'a']++;
    if(cnt1 != cnt2){
        cout << -1 << endl;
        return;
    }

    vvi tsufcnt(n+1, vi(26));
    vvi ssufcnt(n+1, vi(26));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            ssufcnt[i][j] = ssufcnt[i+1][j] + (s[i]-'a' == j);
            tsufcnt[i][j] = tsufcnt[i+1][j] + (t[i]-'a' == j);
        }
    }
    debug(ssufcnt, tsufcnt);

    vvi dp(n+1, vi(n+1, INF));
    for(int i = 0; i <= n; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(tsufcnt[j][t[j-1]-'a'] < ssufcnt[i][t[j-1]-'a']){
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
            if(s[i-1] == t[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        }
    }
    debug(dp);
    cout << dp[n][n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}