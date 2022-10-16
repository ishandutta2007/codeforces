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
    vvi v(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    vi cc(n);
    iota(cc.begin(), cc.end(), 0);
    vi color(n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            debug(i, j, cc, color);
            if(v[i][j] == v[j][i]) continue;
            if(v[i][j] < v[j][i]){
                // want color[i] == color[j]
                if(cc[i] == cc[j]){
                    if(color[i] != color[j]){
                        swap(v[i][j], v[j][i]);
                    }
                }else{
                    int p = cc[j];
                    int x = color[i] ^ color[j];
                    for(int k = 0; k < n; k++){
                        if(cc[k] == p) {
                            cc[k] = cc[i];
                            color[k] ^= x;
                        }
                    }
                }
            }else{
                // want color[i] != color[j]
                if(cc[i] == cc[j]){
                    debug(i, j, color[i], color[j], v[i][j], v[j][i]);
                    if(color[i] != color[j]){
                        swap(v[i][j], v[j][i]);
                    }
                }else{
                    int p = cc[j];
                    int x = color[i] ^ color[j] ^ 1;
                    for(int k = 0; k < n; k++){
                        if(cc[k] == p) {
                            cc[k] = cc[i];
                            color[k] ^= x;
                        }
                    }
                    swap(v[i][j], v[j][i]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
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