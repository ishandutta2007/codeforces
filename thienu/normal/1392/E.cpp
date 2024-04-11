#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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

void solve(){
    int n;
    cin >> n;
    vector<vector<ll>> board(2 * n, vector<ll>(2 * n));
    vector<vector<pair<ll, ll>>> intervals(2 * n, vector<pair<ll, ll>>(2 * n));
    
    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j <= i; j++){
            int x = i-j;
            if(j == 0){
                board[j][x] = 0;
                intervals[j][x] = {0, 0};
            }
            else if(x == 0){
                board[j][x] = 1 << (j-1);
                intervals[j][x] = {(1 << j) - 1, (1 << j) - 1};
            }
            else{
                board[j][x] = board[j][x-1] + board[j-1][x];
                intervals[j][x] = {intervals[j-1][x].first + board[j][x], intervals[j][x-1].second + board[j][x]};
            }
        }
    }

    debug(board);
    debug(intervals[3][3]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout.flush();

    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        pair<int, int> pos = {n-1, n-1};
        vector<pair<int, int>> ans;
        ans.push_back(pos);
        x -= board[pos.first][pos.second];
        for(int i = 0; i < 2 * n - 2; i++){
            if(pos.first > 0 && x >= intervals[pos.first - 1][pos.second].first && x <= intervals[pos.first - 1][pos.second].second){
                pos = {pos.first - 1, pos.second};
            }
            else{
                pos = {pos.first, pos.second - 1};
            }
            ans.push_back(pos);
            x -= board[pos.first][pos.second];
        }
        reverse(ans.begin(), ans.end());
        for(auto p : ans){
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
        cout.flush();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}