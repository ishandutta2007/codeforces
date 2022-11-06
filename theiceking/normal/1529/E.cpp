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
 
const int maxn = (int)3e5 + 105;
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

vector<int>edges1[maxn], edges2[maxn]; 

int  top1 [maxn], top2[maxn], sub1[maxn], sub2[maxn]; 
int rev_top1 [maxn], rev_top2 [maxn]; 

int  cnt1=1, cnt2=1; 
void go1 (int node){
    rev_top1[cnt1] = node; 
    top1[node]=cnt1++; 
    sub1[node] = 1; 
    for (int i : edges1[node]){
        go1(i); 
        sub1[node] += sub1[i]; 
    }
}
void go2 (int node){
    rev_top2[cnt2] = node; 
    top2[node]=cnt2++; 
    sub2[node] = 1; 
    for (int i : edges2[node]){
        go2(i); 
        sub2[node] += sub2[i]; 
    }
}
int ans = 0; 
set <int> s; 
void slv (int node){
    int val = top2[node]; 
    int put = 1, dl = -1; 
    
    auto it = s.lower_bound(val); 
    if (it != s.end() && (*it) <= val + sub2[node] - 1) put = 0; 
    if (put){
        if (it != s.begin()){
            it--; 
            if ((*it) + sub2[rev_top2[*it]] - 1 >= val){
                dl = *it; 
                s.erase(it); 
            }
        }
        s.insert(val); 
    }
    
    ans = max(ans,sz(s)); 
    for (int i : edges1[node]){
        slv(i); 
    }
    if (put){
        s.erase(val); 
        if(dl!=-1) s.insert(dl); 
    }
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int tc;cin>>tc;
    rep (tt, 1, tc){
        ans = 0; cnt1=cnt2=1; 
        int n; cin >> n;
        rep (i, 2, n){
            int a; cin >> a; 
            edges1[a].pb(i); 
        }
        rep (i, 2, n){
            int a; cin >> a; 
            edges2[a].pb(i); 
        }
        go1(1); go2(1);  
        slv(1);
        cout << ans << '\n'; 
        rep (i, 0, n + 5){
            edges1[i].clear(); edges2[i].clear(); 
        }
        s.clear(); 
    }
    return 0; 
}