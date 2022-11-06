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

const int maxn = (int)1e5 + 105;
const int mod = (int)1e9 + 7; 

int ex (int a, int b){
    if(b==0)return 1; int e = ex(a,b/2); e=(1ll*e*e)%mod; if(b&1)e=(1ll*e*a)%mod; return e;
}
int inv (int a){
    return ex(a, mod - 2); 
}
 
#define sz(x) ((int)(x.size()))
 
#define pb push_back
#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)
 
#define pii pair <int, int> 
#define pvi pair <vector <int>, int> 
 
#define pai array <int,2>
#define pdi array <double, 2> 
#define pdt array <double, 3>
 
#define pti array <int,3>
#define pfi array <int,4>
 
#define all(v) v.begin(), v.end()

vector<int>edges[maxn], ed[maxn]; 
vector<pfi>ops; 

int dp [maxn][2]; 
pai opt [maxn][2]; 


void go (int node, int p = 0){
    for (int i : edges[node]){
        if(i==p)continue; 
        ed[node].pb(i); 
        go(i, node); 
    }
}
void solve (int node){
    for (int i : ed[node]){
        solve(i); 
    }
    {// 1 is connected, 0 is disconnected
        int cn1 = -1, cn2=-1; 
        
        int tot=0; 
        for (int j : ed[node]){
            tot += (1 + dp[j][0]); 
            if (dp[j][0] == dp[j][1]){
                if(cn1==-1)cn1=j; 
                else cn2=j; 
            }
        }
        dp[node][0] = tot; if(cn1!=-1)dp[node][0]--; if (cn2!=-1)dp[node][0]--; 
        dp[node][1] = tot; if(cn1!=-1)dp[node][1]--; 
        
        opt[node][0] = {cn1, cn2}; 
        opt[node][1] = {cn1, -1}; 
    }
}
pai construct (int node, int state){
    int start = node, end = node; 
    
    pai vl = opt[node][state]; 
    for (int i : ed[node]){
        if(i==vl[0]||i==vl[1]){
            pai gt = construct(i, 1); 
            if(end==node) end = gt[1]; 
            else start = gt[1]; 
        }
    }
    for (int  i : ed[node]){
        if (i==vl[0]||i==vl[1])continue; 
        pai gt = construct(i,0); 
        ops.pb({node, i, gt[0], end}); 
        end = gt[1]; 
    }
    return {start, end}; 
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int tc; cin >> tc;
    rep (tt, 1, tc){
        ops.clear(); 
        int n; cin >> n; 
        rep (i,1,n-1){
            int a,b;cin>>a>>b;
            edges[a].pb(b);edges[b].pb(a); 
        }
        go(1); 
        solve(1);
        construct(1, 0); 
        cout << sz(ops) << '\n'; 
        for (auto i : ops) cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << '\n'; 
        
        rep (i,1,n){ed[i].clear();edges[i].clear(); }
    }
    return 0; 
}