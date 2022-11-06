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
 
const int maxn = (int)5e3 + 105;
const int mod = (int)998244353; 
 
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

int a [maxn]; 

int query (int a, int b, int c){
    cout << "? " << a << ' ' << b << ' ' << c << endl; 
    int val; cin >> val; 
    return val; 
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int tc; cin >> tc; 
    rep (tt, 1, tc){
        int n; cin >> n; 
        
        int maxi_val = -1, maxi_ind = -1, maxi_count = 0; 
        
        rep (i, 3, n){
            int ret = query (1, 2, i);
            if (ret > maxi_val) maxi_val = ret, maxi_ind = i, maxi_count = 1; 
            else if (ret == maxi_val) maxi_count++; 
        }
        /*
        if (maxi_count == n - 2){ // edge case
            int mx =  -1, mx_ind = -1; 
            rep (i, 1, n - 2){
                int ret = query(i, i + 1, i + 2); 
                if (ret > mx) mx = ret, mx_ind = i; 
            }
            int other = (mx_ind == 1) ? n : 1; 
            if (query(mx_ind, mx_ind + 1, other) == mx) cout << "! " << mx_ind  << ' ' << mx_ind + 1 << endl; 
            else if (query(mx_ind, mx_ind + 2, other) == mx) cout << "! " << mx_ind << ' ' << mx_ind + 2 << endl; 
            else cout << "! " << mx_ind + 1 << ' ' << mx_ind + 2 << endl; 
            continue; 
        }
        */
        vector<int> v; 
        rep (i, 1, n){
            if (i != maxi_ind) v.pb(i); 
        }
        int cp_maxi_ind = maxi_ind; 
        
        maxi_val = -1, maxi_ind = -1; 
        rep (i, 0, sz(v) - 2){
            int ret = query (v[i], v[i+1], cp_maxi_ind);
            if (ret > maxi_val) maxi_val = ret, maxi_ind = i; 
        }
        int other = -1; 
        rep (i,1,n){
            if (i == v[maxi_ind] || i == v[maxi_ind + 1] || i == cp_maxi_ind) continue; 
            other= i; break; 
        }
        if (query(v[maxi_ind], v[maxi_ind + 1], other) == maxi_val) cout << "! " << v[maxi_ind] << ' ' << v[maxi_ind + 1] << endl; 
        else  if (query(v[maxi_ind], cp_maxi_ind, other) == maxi_val) cout << "! " << v[maxi_ind] << ' ' << cp_maxi_ind << endl; 
        else cout << "! " << v[maxi_ind + 1] << ' ' << cp_maxi_ind << endl; 
        
        
    }
    return 0; 
}