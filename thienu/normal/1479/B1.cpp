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

int process_block(int start, int end, vi block){
    int n = block.size();
    if(start != end){
        return n;
    }
    if(n == 1) return 0;
    if(block[1] != start || block[n-2] != end) return n;
    for(int i = 0; i < n-2; i++){
        if(block[i] != block[i+2] && block[i+1] != start){
            return n;
        }
    }
    return n-1;
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int a = 0, b = 0;
    int ans = 0;
    vi block;
    int last = -1;
    for(int i = 0; i < n; i++){
        if(i && v[i] == v[i-1]) continue;
        if((i+1 < n && v[i] == v[i+1])){
            ans += 2;
            if(!block.empty()){
                debug(i, block, last, v[i], process_block(last, v[i], block));
                ans += process_block(last, v[i], block);
                block.clear();
            }
            last = v[i];
        }
        else{
            block.push_back(v[i]);
        }
    }
    if(!block.empty()){
        ans += process_block(last, -2, block);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    // cin >> tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}