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
    int n, m;
    cin >> n >> m;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vpii edges;
    vi degree(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges.push_back({x, y});
        assert(0 <= x && x < n && 0 <= y && y < n);
        degree[x]++;
        degree[y]++;
    }
    debug(degree);

    if(m % 2 == 0){
        cout << 0 << endl;
        return;
    }
    
    int ans = 2e9;
    for(int i = 0; i < n; i++){
        if(degree[i] & 1){
            ans = min(ans, v[i]);
        }
    }
    for(pii p : edges){
        if((degree[p.first] % 2 == 0) && (degree[p.second] % 2 == 0)){
            ans = min(ans, v[p.first] + v[p.second]);
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