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

int gcd(int a, int b){
    if(min(a, b) == 0) return max(a, b);
    return __gcd(a, b);
}

int log2(int x){
    return 31-__builtin_clz(x);
}

void st_set(vi &st, int n, int idx, int val){
    idx += n;
    st[idx] = val;
    for(; idx > 1; idx >>= 1){
        st[idx>>1] = gcd(st[idx], st[idx^1]);
    }
}

int st_gcd(vi &st, int n, int left, int right){
    int res = 0;
    for(left += n, right += n; left < right; left >>= 1, right >>= 1){
        if(left & 1) res = gcd(res, st[left++]);
        if(right & 1) res = gcd(res, st[--right]);
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi v(2*n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[n+i] = v[i];
    }
    debug(log2(n));

    int m = 1<<(log2(n-1)+2);
    debug(m);
    vi st(2*m);
    for(int i = 0; i < 2*n; i++){
        st_set(st, m, i, v[i]);
    }
    int ans = 0;
    int target = st_gcd(st, m, 0, n);
    for(int i = 0; i < n; i++){
        int l = 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(st_gcd(st, m, i, i+mid) == target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans, l-1);
    }
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