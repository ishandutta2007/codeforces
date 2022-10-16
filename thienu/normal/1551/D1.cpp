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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vpii dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool oob(int x, int y, int n, int m){
    return x < 0 || x >= n || y < 0 || y >= m;
}

void output(vvi &domino, int n, int m){
    // debug(domino);
    cout << "YES" << endl;
    return;
    vvi letters(n, vi(m, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // debug("new");
            if(letters[i][j] >= 0) continue;
            vpii v = {{i, j}};
            for(pii d : dir){
                if(oob(i+d.first, j+d.second, n, m)) continue;
                if(domino[i][j] == domino[i+d.first][j+d.second]){
                    v.push_back({i+d.first, j+d.second});
                    break;
                }
            }
            // debug(v);
            set<int> neigh;
            for(pii p : v){
                for(pii d : dir){
                    if(oob(p.first+d.first, p.second+d.second, n, m)) continue;
                    pii pp = {p.first+d.first, p.second+d.second};
                    if(letters[pp.first][pp.second] != -1){
                        neigh.insert(letters[pp.first][pp.second]);
                    }
                }
            }
            // debug(neigh);
            int l = 0;
            for(int x = 0;;x++){
                if(neigh.find(x) == neigh.end()){
                    l = x;
                    break;
                }
            }
            // debug(i, j, l, v);
            for(pii p : v){
                letters[p.first][p.second] = l;
            }
        }
    }
    // debug(letters);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (char)('a'+letters[i][j]);
        }
        cout << endl;
    }
}

vvi transpose(vvi &v, int n, int m){
    vvi out(m, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            out[j][i] = v[i][j];
        }
    }
    return out;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if(n % 2 == 0 && m % 2 == 0){
        if(k & 1){
            cout << "NO" << endl;
            return;
        }
        int cnt = 0;
        vvi out(n, vi(m));
        for(int i = 0; i < n; i+=2){
            for(int j = 0; j < m; j+=2){
                out[i][j] = cnt;
                out[i+1][j+1] = cnt+1;
                if(k > 0){
                    out[i][j+1] = cnt;
                    out[i+1][j] = cnt+1;
                    k-=2;
                }else{
                    out[i][j+1] = cnt+1;
                    out[i+1][j] = cnt;
                }
                cnt+=2;
            }
        }
        output(out, n, m);
    }else{
        bool trans = false;
        if(n & 1){
            trans = true;
            swap(n, m);
            k = n * m / 2 - k;
        }
        // n even, m odd
        if(k & 1 || n*m/2-k < n/2){
            cout << "NO" << endl;
            return;
        }
        // k -= n/2;
        vvi out(n, vi(m));
        int cnt = 0;
        for(int i = 0; i < n; i+=2){
            out[i][m-1] = cnt;
            out[i+1][m-1] = cnt++;
        }
        for(int i = 0; i < n; i+=2){
            for(int j = 0; j < m-1; j+=2){
                out[i][j] = cnt;
                out[i+1][j+1] = cnt+1;
                if(k > 0){
                    out[i][j+1] = cnt;
                    out[i+1][j] = cnt+1;
                    k-=2;
                }else{
                    out[i][j+1] = cnt+1;
                    out[i+1][j] = cnt;
                }
                cnt+=2;
            }
        }
        // debug(out, n, m);
        if(trans){
            out = transpose(out, n, m);
            swap(n, m);
        }
        output(out, n, m);
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