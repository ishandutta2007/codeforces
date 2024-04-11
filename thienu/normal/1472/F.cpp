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
    map<int, int> blocked;
    set<pii> squares;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        y--;
        blocked[y] += x;
        squares.insert({y, x});
    }

    int state = 0;
    int last = 0;
    for(auto it = blocked.begin(); it != blocked.end(); it++){
        int cur = it->first;
        int block = it->second;
        if(state != 0 && ((cur - last) & 1)){
            state = 3 - state;
        }
        debug(cur, block, state);
        if(state == 0){
            if(block == 1){
                state = 1;
            }
            else if(block == 2){
                state = 2;
            }
        }
        else if(state == 1){
            if(block == 2 || block == 3){
                cout << "NO" << endl;
                return;
            }
            if(block == 1){
                state = 0;
            }
        }
        else if(state == 2){
            if(block == 1 || block == 3){
                cout << "NO" << endl;
                return;
            }
            if(block == 2){
                state = 0;
            }
        }
        last = cur + 1;
        debug(last, block, state);
    }
    if(state == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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