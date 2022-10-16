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
    vi a(n), b(n);
    vi pa(n), pb(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        pa[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
        pb[b[i]] = i;
    }


    
    vi cyclen;

    vi vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int cur = i;
        int len = 0;
        while(!vis[cur]){
            vis[cur] = 1;
            len++;
            cur = pa[b[cur]];
        }
        cyclen.push_back(len);
    }

    debug(cyclen);


    ll ans = 0;
    int l = 0, r = n-1;
    for(int i : cyclen){
        if(i == 1) continue;
        vi cyc;
        while(i > 1){
            i -= 2;
            cyc.push_back(l++);
            cyc.push_back(r--);
        }

        for(int j = 0; j < cyc.size() - 1; j++){
            ans += abs(cyc[j] - cyc[j+1]);
        }
        ans += abs(cyc[cyc.size() - 1] - cyc[0]);
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