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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> board;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }
    string x = "";
    for(int i = 0; i < m; i++) x += 'X';
    int start = n % 3 == 0 ? 1 : 0;
    for(int i = start; i < n; i+=3){
        board[i] = x;
        if(i + 2 < n){
            // search for link
            bool found = false;
            for(int j = i + 1; j <= i + 2; j++){
                for(int k = 0; k < m; k++){
                    if(board[j][k] == 'X'){
                        if(j == i+1){
                            board[i+2][k] = 'X';
                        }
                        else{
                            board[i+1][k] = 'X';
                        }
                        found = true;
                        goto finsearch;
                    }
                }
            }
            finsearch:
            if(!found){
                board[i+1][0] = 'X';
                board[i+2][0] = 'X';
            }
        }
    }

    for(string s : board){
        cout << s << endl;
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