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

void handle_2x2(vvi &ans, vvi &v, int i, int j){
    debug(i, j);
    debug(v);
    int s = v[i][j] + v[i][j+1] + v[i+1][j] + v[i+1][j+1];
    vpii ones;
    vpii zeros;
    for(int a = 0; a < 2; a++){
        for(int b = 0; b < 2; b++){
            if(v[i+a][j+b] == 1) ones.push_back({i+a, j+b});
            else zeros.push_back({i+a, j+b});
        }
    }
    if(s == 3){
        ans.push_back({ones[0].first, ones[0].second, ones[1].first, ones[1].second, ones[2].first, ones[2].second});
    }
    else if(s == 2){
        ans.push_back({ones[0].first, ones[0].second, zeros[1].first, zeros[1].second, zeros[0].first, zeros[0].second});
        ans.push_back({ones[1].first, ones[1].second, zeros[1].first, zeros[1].second, zeros[0].first, zeros[0].second});
    }
    else if(s == 1){
        ans.push_back({ones[0].first, ones[0].second, zeros[1].first, zeros[1].second, zeros[0].first, zeros[0].second});
        ans.push_back({ones[0].first, ones[0].second, zeros[1].first, zeros[1].second, zeros[2].first, zeros[2].second});
        ans.push_back({ones[0].first, ones[0].second, zeros[0].first, zeros[0].second, zeros[2].first, zeros[2].second});
    }
    else if(s == 4){
        ans.push_back({ones[0].first, ones[0].second, ones[1].first, ones[1].second, ones[2].first, ones[2].second});
        ans.push_back({ones[0].first, ones[0].second, ones[1].first, ones[1].second, ones[3].first, ones[3].second});
        ans.push_back({ones[0].first, ones[0].second, ones[2].first, ones[2].second, ones[3].first, ones[3].second});
        ans.push_back({ones[1].first, ones[1].second, ones[2].first, ones[2].second, ones[3].first, ones[3].second});
    }
    v[i][j] = 0;
    v[i+1][j+1] = 0;
    v[i+1][j] = 0;
    v[i][j+1] = 0;
}

void upd_squares(map<int, set<pii>> &squares, vvi &v, int a, int b, int n, int m){
    for(int i = max(0, a - 1); i < min(n-1, a + 1); i++){
        for(int j = max(0, b - 1); j < min(m-1, b + 1); j++){
            for(int k = 0; k <= 4; k++){
                squares[k].erase({i, j});
            }
            int s = v[i][j] + v[i][j+1] + v[i+1][j] + v[i+1][j+1];
            squares[s].insert({i, j});
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }

    debug(v);

    vvi ans;
    map<int, set<pii>> squares;

    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j]){
                if(j + 1 < m){
                    ans.push_back({i, j, i+1, j, i, j+1});
                    v[i][j] = 1 - v[i][j];
                    v[i+1][j] = 1 - v[i+1][j];
                    v[i][j+1] = 1 - v[i][j+1];
                }
                else{
                    ans.push_back({i, j, i+1, j-1, i+1, j});
                    v[i][j] = 1 - v[i][j];
                    v[i+1][j-1] = 1 - v[i+1][j-1];
                    v[i+1][j] = 1 - v[i+1][j];
                }
            }
        }
    }

    debug("a");

    for(int j = 0; j < m-2; j++){
        if(v[n-2][j]){
            ans.push_back({n-2, j, n-2, j+1, n-1, j+1});
            v[n-2][j] = 1 - v[n-2][j];
            v[n-2][j+1] = 1 - v[n-2][j+1];
            v[n-1][j+1] = 1 - v[n-1][j+1];
        }
        if(v[n-1][j]){
            ans.push_back({n-1, j, n-2, j+1, n-1, j+1});
            v[n-1][j] = 1 - v[n-1][j];
            v[n-2][j+1] = 1 - v[n-2][j+1];
            v[n-1][j+1] = 1 - v[n-1][j+1];
        }
    }

    debug("b");

    handle_2x2(ans, v, n-2, m-2);

    debug(ans);

    cout << ans.size() << endl;
    for(vi &v : ans){
        for(int i : v){
            cout << i+1 << " ";
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