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

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }

    // belowl[i][j] - # <= j in [0..i)
    vvi belowl(n+1, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i] <= j) belowl[i+1][j] = belowl[i][j] + 1;
            else belowl[i+1][j] = belowl[i][j];
        }
    }

    // belowr[i][j] - # <= j in [i..n)
    vvi belowr(n+1, vi(n));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(v[i] <= j) belowr[i][j] = belowr[i+1][j] + 1;
            else belowr[i][j] = belowr[i+1][j];
        }
    }

    debug(belowl, belowr);

    ll ans = 0;
    for(int b = 0; b < n; b++){
        for(int c = b+1; c < n; c++){
            ans += belowl[b][v[c]] * belowr[c+1][v[b]];
            debug(b, c, ans);
        }
    }
    cout << ans << endl;
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