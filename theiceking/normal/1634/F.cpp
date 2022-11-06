#include <bits/stdc++.h>
 
using namespace std; 
 
 
#define  int long long

template <typename T> 
void print_vec(const vector<T>& v, bool newline = true) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    if (newline) {
        cout << "\n";
    }
}
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
const int maxn = (int)3e5 + 105;
int mod; 
 
#define sz(x) ((int)(x.size()))
 
#define pb push_back
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)
 
int fact_setup=0; int * fact; 
 
int ex (int a, int b){
    if(b==0)return 1; int e = ex(a,b/2); e=(1ll*e*e)%mod; if(b&1)e=(1ll*e*a)%mod; return e;
}
int inv (int a){
    return ex(a, mod - 2); 
}
int choose (int a, int b){
    if(!fact_setup){
        fact_setup=1; 
        fact = new int [maxn]; 
        fact[0]=1; rep (i,1,maxn-1) fact[i]=(i*fact[i-1])%mod; 
    }
    if(a<b)return 0; 
    int num = fact[a]; 
    int denom = (fact[b] * fact[a - b]) % mod; 
    return (num * inv(denom)) % mod; 
}
 
#define pii pair <int, int> 
#define pvi pair <vector <int>, int> 
 
#define pai array <int,2>
#define pdi array <double, 2> 
#define pdt array <double, 3>
 
#define pti array <int,3>
#define pfi array <int,4>
 
#define all(v) v.begin(), v.end()

int A [maxn],  B [maxn]; 
pai fib_start [maxn]; 

set<int>nonzero; 

int  n; 
void correct (int & x){
	x %= mod; if (x < 0) x += mod; 
}
void add_to (int ind, pai val){
	if (ind > n) return; 
	
	fib_start[ind][0] += val[0]; 
	fib_start[ind][1] += val[1]; 
	
	correct(fib_start[ind][0]); 
	correct(fib_start[ind][1]); 
	
	if (fib_start[ind][1] == 0){
		 nonzero.erase(ind);
		if (fib_start[ind][0] != 0) {
			int tmp = fib_start[ind][0]; 
			fib_start[ind][0] = 0; 
			add_to(ind + 1, {0, tmp}); 
		}
	}
	else nonzero.insert(ind); 
}
int fib [ maxn]; 

main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    
    
    
	int q; cin >> n >> q >> mod; 
	fib[0]  = fib[1] = (1%mod) ;
	rep  (i, 2, (int)3e5 + 50) fib[i] = (fib[i - 1] + fib[i - 2]) % mod; 
	
    rep (i, 1, n){
    	int a; cin >> a; 
    	add_to(i, {0, a});
    	add_to(i+ 1, {-a, -a}); 
    }
    rep (i, 1, n){
    	int a; cin >> a; 
    	add_to(i, {0,-a}); 
    	add_to(i+1,  {a,a}); 
    }
    
    rep (i,1, q){
    	char c; cin >> c; 
    	int multiplier = (c == 'A') ? 1 : -1; 
    	
    	int l, r; cin >> l >> r; 
    	add_to(l, {0, multiplier}); 
    	add_to(r+1, {-multiplier*fib[r-l], -multiplier*fib[r+1-l]}); 

    	if (sz(nonzero)) cout << "NO" << '\n';
    	else cout << "YES" << '\n'; 
    }
    return 0; 
}