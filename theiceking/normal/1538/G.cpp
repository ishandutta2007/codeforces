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

main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int tc; cin >> tc;
    rep (tt, 1, tc){
        // N1*a+(val-N1)*b <= x
        // N1*b+(val-N1)*a <= y
        // N1*b - N1 * a <= y -  val * a
        // N1 * a - N1 * b >= val*a - y
        
        // N1 + N2 = val
        // N1 <= min(x/a, y/b)
        // N2 <= min(x/b, y/a)
        
        int x,y,a,b;cin>>x>>y>>a>>b; 
        if(x<y)swap(x,y); 
        if (a<b)swap(a, b); 
        int lo = min(x/a,y/b), hi = 2e9; 
        if(a==b){
            cout<<lo<<'\n'; continue; 
        }
        while (hi>lo){
            int val = (hi+lo+1)/2; 
            int ri = x - val * b; 
            if(ri<0){
                hi=val-1;continue; 
            }
            int mx_n1 = min(val, ri / (a - b));
            if(mx_n1 * (a - b) >= val * a - y){
                lo = val; 
            }
            else hi = val - 1; 
        }
        cout << lo << '\n'; 
    }
    return 0; 
}