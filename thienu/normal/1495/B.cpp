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
    int n;
    cin >> n;
    vi p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vi left(n);
    vi right(n);
    int max_incline = 0;
    for(int i = 1; i < n; i++){
        if(p[i] > p[i-1]) left[i] = left[i-1] + 1;
        max_incline = max(max_incline, left[i]);
    }
    for(int i = n-2; i >= 0; i--){
        if(p[i] > p[i+1]) right[i] = right[i+1] + 1;
        max_incline = max(max_incline, right[i]);
    }
    debug(left, right, max_incline);
    int ans = 0;
    int peak_idx = -1;
    for(int i = 0; i < n; i++){
        if(left[i] == max_incline || right[i] == max_incline){
            if(peak_idx == -1) peak_idx = i;
            else{
                cout << 0 << endl;
                return;
            }
        }
    }
    int lower = min(left[peak_idx], right[peak_idx]);
    int higher = max(left[peak_idx], right[peak_idx]);
    debug(peak_idx, lower, higher);
    if((lower & 1) || (higher >= lower + 1)){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}