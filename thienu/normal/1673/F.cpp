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
    int n, k;
    cin >> n >> k;
    vi row(31), col(31);
    for(int i = 0; i < 31; i++){
        row[i] = 1 << (2 * __builtin_ctz(i+1));
        col[i] = row[i] << 1;
    }
    debug(row, col);

    vvi vals(32, vi(32));
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            if(i == j && j == 0) continue;
            if(i == 0) vals[i][j] = vals[i][j-1] ^ row[j-1];
            else vals[i][j] = vals[i-1][j] ^ col[i-1];
        }
    }

    debug(vals);

    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            cout << row[j] << ' ';
            sum += row[j];
        }
        cout << endl;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            cout << col[i] << ' ';
            sum += col[i];
        }
        cout << endl;
    }
    debug(sum);

    int r = 0, c = 0;

    while(k--){
        int start_val = vals[r][c];
        int end_val;
        cin >> end_val;
        int diff = start_val ^ end_val;
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < 32; j++){
                if(vals[i][j] == diff){
                    cout << i+1 << ' ' << j+1 << endl;
                    r = i;
                    c = j;
                    goto nxt;
                }
            }
        }
        nxt:
        ;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}