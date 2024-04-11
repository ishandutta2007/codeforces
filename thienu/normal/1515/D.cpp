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
    int n, l, r;
    cin >> n >> l >> r;
    vi left(n);
    vi right(n);
    int ans = 0;
    for(int i = 0; i < l; i++){
        int x;
        cin >> x;
        x--;
        left[x]++;
    }
    for(int i = 0; i < r; i++){
        int x;
        cin >> x;
        x--;
        right[x]++;
    }

    for(int i = 0; i < n; i++){
        int same = min(left[i], right[i]);
        left[i] -= same;
        right[i] -= same;
        l -= same;
        r -= same;
    }
    for(int i = 0; i < n; i++){
        if(l <= r) break;
        while(l > r && left[i] >= 2){
            left[i] -= 2;
            l -= 2;
            ans++;
        }
    }
    for(int i = 0; i < n; i++){
        if(r <= l) break;
        while(r > l && right[i] >= 2){
            right[i] -= 2;
            r -= 2;
            ans++;
        }
    }
    ans += abs(r - l) / 2;
    ans += (r + l) / 2;
    cout << ans << endl;
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