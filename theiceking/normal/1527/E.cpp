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
 
const int maxn = (int)35505;
const int mod = (int)1e9 + 7; 
 
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

int arr [maxn]; 
int ne [maxn]; 
int st[maxn]; 

int dp [maxn]; 

int seg [4 * maxn]; 
int lz [4 * maxn]; 

void build (int start, int end, int node = 1){
	lz[node] = 0;
	if (start == end){
		seg[node] = dp[start]; return; 
	}
	build (start, (start+end)/2, 2*node); 
	build ((start+end)/2+1, end, 2*node+1); 
	seg[node]=min(seg[2*node],seg[2*node+1]);
}

void push (int start, int end, int node){
	if(lz[node]){
		seg[node]+=lz[node]; 
		if(start!=end){
			lz[2*node]+=lz[node]; lz[2*node+1]+=lz[node]; 
		}
		lz[node]=0; 
	}
}
void update (int start, int end, int i, int j, int val, int node=1){
	push(start,end,node); 
	if(start>j||end<i)return; 
	if(start>=i&&end<=j){
		lz[node]=val;push(start,end,node); return; 
	}
	update(start,(start+end)/2,i,j,val,2*node); 
	update((start+end)/2+1,end,i,j,val,2*node+1); 
	seg[node]=min(seg[2*node],seg[2*node+1]); 
}
int query (int start, int end, int i, int j, int node=1){
	push(start,end,node); 
	if(start>j||end<i)return 1e18; 
	if(start>=i&&end<=j)return seg[node]; 
	return min(query(start,(start+end)/2,i,j,2*node),query((start+end)/2+1,end,i,j,2*node+1)); 
}
main(){
	memset(ne, -1, sizeof(ne)); 
	
    cin.tie(0); ios_base::sync_with_stdio(0); 
	
	int n, k; cin >> n >> k;
	rep (i, 1, n) cin  >> arr[i]; 
	repr (i, n, 1){
		if (st[arr[i]]) ne[i] =  st[arr[i]]; 
		st[arr[i]] = i; 
	}
	rep (i, 1, n) dp[i] = 1e18; 
	
	dp[n + 1] = 0; 
	
	rep (i, 1, k){
		build (1, n + 1); 
		dp[n + 1] = 1e18; 
		repr (j, n, 1){
			dp[j] = 1e18; 
			if (ne[j] != -1) update (1, n + 1, ne[j] + 1, n + 1, ne[j]  -  j);
			dp[j] = min(dp[j], query(1, n + 1, j + 1, n + 1)); 
		}
	}
	cout << dp[1]; 
    return 0; 
}