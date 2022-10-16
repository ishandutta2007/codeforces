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

const int H = 100;
const int N = 9;

const int D = 405;
// const int D = 50;

using vc = vector<char>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;

int xc(int num){
    return num * 3;
}

void solve(){
    int n;
    cin >> n;
    vvi mat(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    vvvc board(D, vvc(6, vc(45, '#')));
    for(int i = 0; i < n; i++){
        board[0][2][xc(i)] = '.';
        board[0][3][xc(i)] = '.';
        board[0][4][xc(i)] = '.';
        // build drop + stairs
        board[0][5][xc(i)] = char('1'+i);
        board[0][5][xc(i)+1] = '.';
        board[0][0][xc(i)] = '.';
        board[0][0][xc(i)+1] = '.';
        board[0][1][xc(i)] = '.';
        for(int j = 1; j < D; j++){
            board[j][5][xc(i)] = '.';
            board[j][5][xc(i)+1] = '.';
            if(j % 4 != 2) board[j][0][xc(i)] = '.';
            if(j % 4 != 3) board[j][0][xc(i)+1] = '.';
            if(j % 4 != 1) board[j][1][xc(i)] = '.';
            if(j % 4 != 0) board[j][1][xc(i)+1] = '.';
            if(j % 4 == 1){
                board[j][5][xc(i)] = '#';
            }else if(j % 4 == 3){
                board[j][5][xc(i)+1] = '#';
            }
        }
    }

    // tunnels
    for(int i = 1; i <= H; i++){
        for(int j = 0; j < 45; j++){
            board[4*i][3][j] = '.';
        }
    }

    int nt = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j]){
                board[nt*4-2][4][xc(i)+1] = '.';
                board[nt*4-2][3][xc(i)+1] = '.';
                board[nt*4-1][3][xc(i)+1] = '.';
                board[nt*4][2][xc(j)] = '.';
                nt++;
            }
        }
    }

    cout << board[0][0].size() << ' ' << board[0].size() << ' ' << board.size() << endl;
    for(auto a : board){
        for(auto b : a){
            for(auto c : b){
                cout << c;
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}