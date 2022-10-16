#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset
#define int long long
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
#undef int
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
#define int long long
const int INF = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vi pts(n);
    for(int i = 0; i < n; i++) cin >> pts[i];
    sort(pts.begin(), pts.end());
    vector<vpii> seg(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        auto it = upper_bound(pts.begin(), pts.end(), y);
        if(it != pts.begin() && x <= *prev(it)) continue;
        seg[it-pts.begin()].push_back({x, y});
    }
    debug(seg);
    for(int i = 0; i < n+1; i++){
        sort(seg[i].begin(), seg[i].end());
        vpii ns;
        int lst = -INF;
        int lstx = -INF;
        for(pii p : seg[i]){
            if(p.first == lstx) continue;
            while(!ns.empty() && p.second <= prev(ns.end())->second) ns.pop_back();
            ns.push_back(p);
            lstx = p.first;
            lst = p.second;
        }
        seg[i] = ns;
    }
    debug(seg);
    vector<vpii> constraints(n+1);
    constraints[0] = {{0, seg[0].empty() ? 0 : pts[0] - seg[0][0].second}};
    constraints[n] = {{seg[n].empty() ? 0 : seg[n][seg[n].size()-1].first - pts[n-1], 0}};
    for(int i = 1; i < n; i++){
        debug(i);
        if(seg[i].empty()) constraints[i] = {{0, 0}};
        else{
            constraints[i].push_back({0, pts[i] - seg[i][0].second});
            for(int j = 0; j+1 < seg[i].size(); j++){
                constraints[i].push_back({seg[i][j].first - pts[i-1], pts[i] - seg[i][j+1].second});
            }
            constraints[i].push_back({seg[i][seg[i].size()-1].first - pts[i-1], 0});
        }
    }
    debug(constraints);

    vll last_ans = {0};
    for(int i = 1; i <= n; i++){
        ll plus_r = 1e18, plus_2r = 1e18;
        for(int j = 0; j < constraints[i-1].size(); j++){
            plus_r = min(plus_r, last_ans[j] + constraints[i-1][j].second);
            plus_2r = min(plus_2r, last_ans[j] + 2LL * constraints[i-1][j].second);
        }
        debug(i, plus_r, plus_2r);

        vll ans(constraints[i].size());
        for(int j = 0; j < ans.size(); j++){
            int l = constraints[i][j].first;
            ans[j] = min(plus_r + 2LL * l, plus_2r + l);
        }

        last_ans = ans;
        debug(i, last_ans);
    }
    debug(last_ans);
    cout << last_ans[0] << endl;
}
#undef int
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