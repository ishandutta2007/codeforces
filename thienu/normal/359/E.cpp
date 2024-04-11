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

map<char, pii> directions;
vector<char> letters = {'U', 'D', 'L', 'R'};

string ans = "";

int n, x, y;

vvi board;
vvi vis;
vvi depth;

void move(char c){
    pii d = directions[c];
    ans += c;
    x += d.first;
    y += d.second;
}

char opposite(char c){
    switch(c){
        case 'U': return 'D';
        case 'D': return 'U';
        case 'L': return 'R';
        case 'R': return 'L';
        default: return c;
    }
}

void create(){
    board[x][y] = 1;
    ans += '1';
}

void remove(){
    board[x][y] = 0;
    ans += '2';
}

void visit(int a, int b, int d){
    depth[a][b] = d;
    if(!board[a][b]){
        create();
    }
    vis[a][b] = 1;
    // raycast
    for(char c : letters){
        if(vis[a + directions[c].first][b + directions[c].second]) continue;
        bool ok = false;
        int x1, y1;
        for(int k = 1;; k++){
            x1 = a + directions[c].first * k;
            y1 = b + directions[c].second * k;
            if(x1 < 1 || x1 > n || y1 < 1 || y1 > n) break;
            if(board[x1][y1]){
                ok = true;
                break;
            }
        }
        if(ok){
            move(c);
            visit(x, y, d+1);
            move(opposite(c));
        }
    }
}

void off(){
    for(char c : letters){
        int x1 = x + directions[c].first;
        int y1 = y + directions[c].second;
        if(depth[x1][y1] > depth[x][y] && board[x1][y1]){
            move(c);
            off();
            move(opposite(c));
        }
    }
    remove();
}

void solve(){
    cin >> n >> x >> y;
    // vvi board(n+2, vi(n+2));
    // vvi vis(n+2, vi(n+2));
    board.resize(n+2);
    fill(board.begin(), board.end(), vi(n+2));
    vis.resize(n+2);
    fill(vis.begin(), vis.end(), vi(n+2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    if(!board[x][y]){
        create();
    }
    // debug(ans);
    // debug(board);
    depth.resize(n+2);
    fill(depth.begin(), depth.end(), vi(n+2, -1));
    visit(x, y, 0);
    // debug(ans, board, vis);
    // debug(depth);
    debug("visit done");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] && !vis[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }

    off();
    cout << "YES" << endl;
    cout << ans << endl;
}

int main(){

    directions['U'] = {-1, 0};
    directions['D'] = {1, 0};
    directions['L'] = {0, -1};
    directions['R'] = {0, 1};

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}