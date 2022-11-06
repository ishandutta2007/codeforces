#include <bits/stdc++.h>
 
using namespace std; 
 
#define int long long 
 
 
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
 
const int maxn = (int)2e5 + 105;
const int mod = (int)998244353 ; 
 
#define sz(x) ((int)(x.size()))
 
#define pb push_back
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)
 
using vi = vector<int>;
 
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


pai arr [maxn]; 

int suff [maxn]; 

int n;
int go (int i, int bought){
	if (i == n + 1) return 0; 
	
	int need_buy = arr[i][1], cost = 0; 
	if (bought < arr[i][0]){
		cost = (arr[i][0] - bought); 
		bought = arr[i][0]; 
	}
	cost += need_buy; 
	bought += need_buy; 
	return min(suff[i], cost + go(i + 1, bought)); 
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
	 cin >> n; 
	 int tot = 0; 
	rep (i,1,n){
		int need, disc; cin >> need >> disc; 
		tot+=need; 
		arr[i] = {disc,  need}; 
	}
	sort(arr+1, arr+n+1); 
	int mi = arr[1][0]; int mi_copy = mi; 
	repr (i, n, 1){
		int take = min(arr[i][1], mi); 
		arr[i][1] -= take; 
		mi -= take; 
	}
	repr (i, n, 1) suff[i] = 2 * arr[i][1] + suff[i + 1]; 
	
	cout << min(2*tot, 2 * mi_copy + go (1, mi_copy)) << '\n'; 
    return 0; 
}