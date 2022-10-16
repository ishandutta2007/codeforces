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

ll INF = 1e18;

void solve(){
    int f, T, t0, a1, t1, p1, a2, t2, p2;
    cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;
    
    if(t1 > t2){
        swap(t1, t2);
        swap(p1, p2);
        swap(a1, a2);
    }

    ll ans = INF;
    for(int x1 = 0; (x1-1) * a1 * t1 <= T; x1++){
        ll time = min(x1 * a1 * t1, T);
        int time_left = T - time;
        ll cur_price = 1LL * x1 * p1;
        int bytes_left = f - time / t1;
        debug(x1, time, time_left, cur_price, bytes_left);
        if(bytes_left - time_left / t0 <= 0){
            ans = min(ans, cur_price);
            continue;
        }
        if(bytes_left - time_left / t2 > 0) continue;

        int cur = (1<<24)-1;
        for(int add = (1<<24); add; add>>=1){
            int mid = cur - add;
            int plan_time = min((ll) time_left, 1LL * a2 * t2 * mid);
            int total_bytes = plan_time / t2 + (time_left - plan_time) / t0;
            debug(x1, mid, plan_time, time_left, bytes_left, total_bytes);
            if(total_bytes >= bytes_left){
                cur = mid;
            }
        }
        ans = min(ans, cur_price + 1LL * cur * p2);
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}