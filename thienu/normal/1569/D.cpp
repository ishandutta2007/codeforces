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
    int n, m, k;
    cin >> n >> m >> k;
    set<int> xs, ys;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        xs.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        ys.insert(x);
    }
    vector<map<int, map<int, int>>> pts(2);
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        bool onx = xs.find(x) != xs.end(), ony = ys.find(y) != ys.end();
        // debug(i, onx, ony);
        if(onx && ony) continue;
        int idx;
        int pri, sec;
        if(onx){
            idx = 0;
            pri = *ys.upper_bound(y);
            sec = x;
        }else{
            idx = 1;
            pri = *xs.upper_bound(x);
            sec = y;
        }
        pts[idx][pri][sec]++;
    }
    debug(pts);

    ll ans = 0;
    for(auto &pt : pts){
        for(auto &m : pt){
            auto mp = m.second;
            ll total = 0;
            for(pii p : mp){
                total += p.second;
                ans -= (1LL * (p.second) * (p.second - 1)) / 2LL;
            }
            ans += (1LL * total * (total - 1)) / 2LL;
            debug(m, ans);
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