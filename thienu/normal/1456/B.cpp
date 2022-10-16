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

const int INF = 1e9 + 5;

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 1; i+1 < n; i++){
        if(v[i] == v[i+1]){
            cout << 1 << endl;
            return;
        }
    }

    vi cnt_msb(30);
    for(int i : v){
        cnt_msb[31 - __builtin_clz(i)]++;
    }

    debug(cnt_msb);
    
    if(*max_element(cnt_msb.begin(), cnt_msb.end()) >= 3){
        cout << 1 << endl;
        return;
    }

    vi pref(n+1);
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i] ^ v[i];
    }

    int ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            // int x = pref[i] ^ pref[j+1];
            // if((j + 1 < n && x > v[j+1]) || (i - 1 >= 0 && x < v[i-1])){
            //     debug(i, j, x);
            //     ans = min(ans, j - i);
            // }
            for(int k = j + 1; k < n; k++){
                int x = pref[i] ^ pref[j+1];
                int y = pref[j+1] ^ pref[k+1];
                if(x > y){
                    debug(i, j, k, x, y);
                    ans = min(ans, k - i - 1);
                }
            }
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}