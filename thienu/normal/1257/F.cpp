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
    vi low(n), high(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        high[i] = (x >> 15) << 15;
        low[i] = high[i] ^ x;
    }

    map<vi, int> low_cnt;
    for(int m = 0; m < (1 << 15); m++){
        vi one(n);
        for(int i = 0; i < n; i++){
            one[i] = __builtin_popcount(m ^ low[i]);
        }
        vi diff(n-1);
        for(int i = 0; i+1 < n; i++){
            diff[i] = one[i+1] - one[i];
        }
        low_cnt[diff] = m;
    }

    map<vi, int> high_cnt;
    for(int m = 0; m < (1 << 30); m+=(1 << 15)){
        vi one(n);
        for(int i = 0; i < n; i++){
            one[i] = __builtin_popcount(m ^ high[i]);
        }
        vi diff(n-1);
        for(int i = 0; i+1 < n; i++){
            diff[i] = -one[i+1] + one[i];
        }
        high_cnt[diff] = m;
    }
    
    for(auto it = low_cnt.begin(); it != low_cnt.end(); it++){
        vi ld = it->first;
        if(high_cnt.find(ld) != high_cnt.end()){
            cout << (it->second | high_cnt[it->first]) << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}