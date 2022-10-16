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

using vc = vector<char>;
using vvc = vector<vc>;

bool win(char a, char b, char c){
    return a == b && b == c && c != '.';
}

void solve(){
    int n;
    cin >> n;
    vvc grid(n, vc(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '.') total++;
        }
    }

    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            if(a == b) continue;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(((i + j) % 3 == a && grid[i][j] == 'X') || ((i + j) % 3 == b && grid[i][j] == 'O')) cnt++;
                }
            }
            debug(a, b, cnt);
            if(cnt <= total / 3){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if((i + j) % 3 == a && grid[i][j] == 'X') grid[i][j] = 'O';
                        else if((i + j) % 3 == b && grid[i][j] == 'O') grid[i][j] = 'X';
                    }
                }
                goto end;
            }
        }
    }

    end:

    debug(grid);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j];
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