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
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    set<int> a;
    set<int> b;
    int p = n / 2;
    int q = n - p;
    if(n == 1){
    	cout << v[0] % m << endl;
    	return;
    }
    debug(p, q);
    for(int mask = 0; mask < (1 << p); mask++){
    	int sum = 0;
    	for(int j = 0; j < p; j++){
    		if((mask >> j) & 1){
    			sum = (sum + v[j]) % m;
    		}
    	}
    	a.insert(sum);
    }
    
    for(int mask = 0; mask < (1 << q); mask++){
    	int sum = 0;
    	for(int j = 0; j < q; j++){
    		if((mask >> j) & 1){
                debug(mask, j);
    			sum = (sum + v[p+j]) % m;
    		}
    	}
    	b.insert(sum);
    }
    
    debug(a, b);
    // cout << *a.begin() << " " << *prev(a.end()) << endl;
    int ans = 0;
    auto bt = prev(b.end());
    for(auto it = a.begin(); it != a.end(); it++){
    	while(*it + *bt >= m){
    		bt--;
    	}
    	ans = max(ans, *it + *bt);
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}