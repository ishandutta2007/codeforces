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
    vi v(n*m);
    for(int i = 0; i < n*m; i++) cin >> v[i];
    vi s = v;
    sort(s.begin(), s.end());
    map<int, int> first, last;
    for(int i = 0; i < n*m; i++){
        last[s[i]] = i;
    }
    for(int i = n*m-1; i >= 0; i--){
        first[s[i]] = i;
    }
    debug(first, last);
    vi taken(n*m);
    vi full(n);
    int ans = 0;
    for(int i = 0; i < n*m; i++){
        int rowl = last[v[i]] / m;
        int rowf = first[v[i]] / m;
        debug(i, v[i], rowl, rowf);
        int fr, fallback;
        if(rowf == rowl) fr = fallback = rowf;
        else{
            bool can = false;
            for(int j = 0; j < m; j++){
                if(!taken[rowf*m+j] && s[rowf*m+j] == v[i]) can = true;
            }
            if(can) fr = rowf;
            else{
                fr = rowf + 1;
                while(fr < n && full[fr]) fr++;
            }
            fallback = rowl;
        }
        debug(fr, fallback);
        int cur_row = fr;
        int cur_col;
        for(int j = m-1; j >= 0; j--){
            if(!taken[cur_row*m + j] && s[cur_row*m+j] == v[i]){
                cur_col = j;
                goto done;
            }
        }
        cur_row = fallback;
        for(int j = m-1; j >= 0; j--){
            if(!taken[cur_row*m + j] && s[cur_row*m+j] == v[i]){
                cur_col = j;
                goto done;
            }
        }

        done:;
        debug(cur_row, cur_col);
        taken[cur_row*m+cur_col] = 1;
        for(int j = cur_col - 1; j >= 0; j--){
            if(taken[cur_row*m+j]) ans++;
        }
        bool f = true;
        for(int j = 0; j < m; j++){
            if(!taken[cur_row*m+j]) f = false;
        }
        full[cur_row] = f;
        debug(ans, taken);
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