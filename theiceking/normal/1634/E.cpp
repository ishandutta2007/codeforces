#include <bits/stdc++.h>
 
using namespace std; 
 
 
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

vector <int> arr [maxn]; 
map <int, vector<pai> > number_loc; 
vector<int> remaining_num [maxn]; 

map <pai, pai> pairr; 


map <pai,int> vis; 

map <pai,int> ans; 

main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int m; cin >> m; 
    map <int, int> mp; 
    
    vector<pai> all_remaining_num; 
    rep (i, 1, m){
        int n; cin >> n; 
        map <int, vector <int> > pos; 
        
        rep (j, 1, n) {
            int k; cin >> k; 
            arr[i].pb(k);  
            mp[k]++; 
            pos[k].pb(j); 
        }
        
        for (auto j = pos.begin(); j != pos.end(); j++){
            vector <int> loc = j->second; 
            while (sz(loc) >= 2){
                int val1 = loc.back(), val2 = loc[sz(loc) - 2]; 
                ans[{i, val1}] = 0; 
                ans[{i, val2}] = 1; 
                loc.pop_back(); loc.pop_back();  
            }
            if(sz(loc) == 1){
                number_loc[j->first].pb({i, loc[0]});
                remaining_num[i].pb(loc[0]); 
                all_remaining_num.pb({i, loc[0]}); 
            }
        }
        
        
    }
    for (auto i = mp.begin(); i != mp.end(); i ++){
        if ((i->second)&1){
            cout  << "NO"; return 0; 
        }
    }
    
    for (auto i = number_loc.begin(); i !=  number_loc.end(); i++){
        vector<pai> all = i->second; 
        for (int j = 0; j < sz(all); j += 2){
            pairr[all[j]] = all[j + 1]; 
            pairr[all[j + 1]] = all[j];
        }
    }
    
    for (pai i : all_remaining_num){
        if(vis[i])continue; 
        pai cur = i; 
        int orig = i[0]; 
        
        while (1){
            vis[cur] = 1; vis[pairr[cur]] = 1;  
            ans[cur] = 0; ans[pairr[cur]] = 1;  
            if (pairr[cur][0] == orig) break; // we completed cycle
            
            int  ind = pairr[cur][0]; 
            while(sz(remaining_num[ind]) && vis[{ind, remaining_num[ind].back()}]) remaining_num[ind].pop_back(); 
            
            cur = {ind, remaining_num[ind].back()}; 
        }
    }
    cout << "YES" << '\n'; 
    
    rep (i, 1,  m){
        rep (j, 1, sz(arr[i])){
            if (ans[{i, j}]) cout << 'R'; 
            else cout << 'L'; 
        }
        cout << '\n'; 
    }
        
    return 0; 
}