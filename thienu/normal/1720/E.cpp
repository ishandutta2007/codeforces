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

void add_rect(vvi &r, int xmn, int xmx, int ymn, int ymx, int d){
    r[xmn][ymn] += d;
    r[xmn][ymx] -= d;
    r[xmx][ymn] -= d;
    r[xmx][ymx] += d;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vvi v(n, vi(n));
    vi cnt(n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
            v[i][j]--;
            cnt[v[i][j]]++;
        }
    }
    int unique = 0;
    for(int i = 0; i < n*n; i++){
        if(cnt[i]) unique++;
    }
    debug(cnt, unique);
    if(k >= unique){
        cout << k - unique << endl;
        return;
    }

    vi xmn(n*n, 1e9);
    vi xmx(n*n, -1e9);
    vi ymn(n*n, 1e9);
    vi ymx(n*n, -1e9);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            xmn[v[i][j]] = min(xmn[v[i][j]], i);
            xmx[v[i][j]] = max(xmx[v[i][j]], i);
            ymn[v[i][j]] = min(ymn[v[i][j]], j);
            ymx[v[i][j]] = max(ymx[v[i][j]], j);
        }
    }

    debug(xmn, xmx, ymn, ymx);

    for(int sz = 1; sz <= n; sz++){
        debug(sz);
        int lim = n - sz + 1;
        vvi nelim_pref(lim+1, vi(lim+1));
        for(int col = 0; col < n*n; col++){
            if(cnt[col] == 0) continue;
            int sxmn = max(0, xmx[col] - sz + 1);
            int sxmx = min(lim, xmn[col] + 1);
            int symn = max(0, ymx[col] - sz + 1);
            int symx = min(lim, ymn[col] + 1);
            debug(col, sxmn, sxmx, symn, symx);
            if(sxmn >= sxmx || symn >= symx) continue;
            add_rect(nelim_pref, sxmn, sxmx, symn, symx, 1);
        }
        debug(nelim_pref);
        for(int i = 0; i <= lim; i++){
            for(int j = 0; j < lim; j++){
                nelim_pref[i][j+1] += nelim_pref[i][j];
            }
        }
        for(int i = 0; i < lim; i++){
            for(int j = 0; j <= lim; j++){
                nelim_pref[i+1][j] += nelim_pref[i][j];
            }
        }
        debug(nelim_pref);
        for(int i = 0; i <= lim; i++){
            for(int j = 0; j <= lim; j++){
                if(unique - nelim_pref[i][j] == k || unique - nelim_pref[i][j] == k-1){
                    cout << 1 << endl;
                    return;
                }
            }
        }
    }

    cout << 2 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}