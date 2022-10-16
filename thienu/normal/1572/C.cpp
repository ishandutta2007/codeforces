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
    vi v(n);
    vvi pos(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
        pos[v[i]].push_back(i);
    }

    // [L, R)
    vvi dp(n+1, vi(n+1, INF));
    for(int i = 0; i <= n; i++) dp[i][i] = 0;
    // for(int d = 1; d <= n; d++){
    //     for(int l = 0, r = l+d; r <= n; l++,r++){
    //         // [l, r)
    //         int x = v[l];
    //         int s = 0;
    //         int lst = -1;
    //         vi sect;
    //         for(int c : pos[x]){
    //             if(c < l || c >= r) continue;
    //             sect.push_back(c);
    //         }
    //         sect.push_back(r);
    //         vi dp2(sect.size(), INF);
    //         dp2[0] = 0;
    //         for(int i = 1; i < sect.size(); i++){
    //             for(int j = 0; j < i; j++){
    //                 dp2[i] = min(dp2[i], dp2[j] + dp[sect[j]+1][sect[i]] + (sect[j]+1 != sect[i]));
    //             }
    //         }
    //         debug(l, r, sect, dp2);
    //         // if(lst+1 != r) s += dp[lst+1][r] + 1;
    //         // debug(l, r, s);
    //         dp[l][r] = dp2[sect.size()-1];
    //     }
    // }
    for(int l = n-1; l >= 0; l--){
        int x = v[l];
        int s = 0;
        int lst = -1;
        vi sect;
        for(int c : pos[x]){
            if(c < l) continue;
            sect.push_back(c);
        }
        sect.push_back(n);
        vi dp2(sect.size(), INF);
        dp2[0] = 0;
        for(int i = 1; i < sect.size(); i++){
            for(int j = 0; j < i; j++){
                dp2[i] = min(dp2[i], dp2[j] + dp[sect[j]+1][sect[i]] + (sect[j]+1 != sect[i]));
            }
        }
        for(int r = l+1; r <= n; r++){
            for(int x = 0; x < sect.size() && sect[x] < r; x++){
                dp[l][r] = min(dp[l][r], dp2[x] + dp[sect[x]+1][r] + (v[r-1] != v[l] || sect[x]+1 != r));
            }
        }
    }
    debug(dp);
    cout << dp[0][n] << endl;
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