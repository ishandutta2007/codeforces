#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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
    ll n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    ll p, q, cur;
    if(a > c){
        swap(a, c);
        swap(b, d);
    }
    if(b < c){
        p = c-b;
        cur = 0;
    }
    else{
        p = 0;
        cur = (min(b, d)-max(a, c)) * n;
    }
    q = abs(d-b) + abs(c-a);
    debug(p, q, cur);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(cur >= k){
            break;
        }
        if(cur + (q-p) >= k){
            ans += p + (k - cur);
            cur = k;
            break;
        }
        cur += q-p;
        ans += q;
        if(cur + p >= k){
            ans += (k - cur) * 2;
            cur = k;
            break;
        }
        debug(cur, ans);
    }
    if(cur < k){
        ans += (k - cur) * 2;
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