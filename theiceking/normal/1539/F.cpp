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

int mini [8 * maxn], maxi [8 * maxn], lazy [8 * maxn]; 

vector <int> ins [maxn]; 
int arr [maxn], ans [maxn]; 

void push (int node){
    if (lazy[node]){
        mini[node] += lazy[node]; maxi[node] += lazy[node]; 
        lazy[2 * node] += lazy[node]; lazy[2 * node + 1] += lazy[node]; 
        lazy[node] = 0; 
    }
}
void upd (int start, int end, int i, int j, int val, int node=1){
    push(node); 
    if (start>j||end<i) return; 
    if (start>=i&&end<=j){
        lazy[node] = val; push(node); return; 
    }
    upd(start, (start+end)/2,i,j,val,2*node); 
    upd((start+end)/2+1,end,i,j,val,2*node+1); 
    mini[node]=min(mini[2*node],mini[2*node+1]); 
    maxi[node]=max(maxi[2*node],maxi[2*node+1]); 
}
int query (int start, int end, int i, int j, int type, int node=1){
    push(node); 
    if (start>j||end<i){
        if(type==0) return 1e18; 
        else return -1e18; 
    }
    if (start>=i && end<=j){
        if (type == 0) return mini[node]; 
        return maxi[node]; 
    }
    if(type==0)return min(query(start, (start+end)/2, i, j, type, 2*node), query((start+end)/2+1, end, i, j, type, 2*node+1));
    else return max(query(start, (start+end)/2, i, j, type, 2*node), query((start+end)/2+1, end, i, j, type, 2*node+1));
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int n; cin >> n; 
    rep (i, 1, n){
        upd (0, n, i, n, -1); 
    }
    rep (i, 1, n){
        cin >> arr[i]; 
        ins[arr[i]].pb(i); 
    }
    repr (i, n, 1){
        for (int j : ins[i]){
            int fi = query (0, n, j, n, 0) - query(0, n, 0, j - 1, 1);
            ans[j] = max(ans[j], (-fi - 1) / 2); 
        }
        for (int j : ins[i]){
            upd (0, n, j, n, 2); 
        }
        for (int j : ins[i]){
            int fi = query (0, n, j, n, 1) - query (0, n, 0, j - 1, 0); 
            ans[j] = max(ans[j], fi/2); 
        }
    }
    rep (i,1,n) cout << ans[i] << ' '; 
    return 0; 
}