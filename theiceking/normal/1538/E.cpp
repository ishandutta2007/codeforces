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

map <string, int> leng, occ; 
map<string, bool> suff [3]; 
map<string, bool> pref [3]; 
map<string, string> latest; 

int fin (string s, string target){
   int occurrences = 0;
   std::string::size_type pos = 0;

    while ((pos = s.find(target, pos )) != std::string::npos) {
          ++ occurrences;
          pos += target.length();
   }
   return occurrences; 
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int tc; cin >> tc;
    rep (tt, 1, tc){
        leng.clear(); rep (i,0,2){
            suff[i].clear(); pref[i].clear();  
        }
        int n; cin >> n; 
        rep (zz, 1, n){
            string var_name; cin >> var_name; 
            string tmp = var_name; 
            string op; cin >> op; 
            
            if (sz(latest[var_name])){
                var_name = latest[var_name] + 'a'; 
            }

            if (op == ":="){
                string as; cin >> as;
                leng[var_name] = sz(as); 
                occ[var_name] = fin(as, "haha"); 
                if(zz==n) cout << occ[var_name] << '\n'; 
                string tr =  "haha"; 
                
                rep (i,0,2){
                    if(i+1>sz(as))break; 
                    if (as.substr(0, i+1) == tr.substr(sz(tr)-1-i, i+1)) pref[i][var_name]=1;
                    if (as.substr(sz(as)-1-i, i+1) == tr.substr(0, i+1)) suff[i][var_name]=1; 
                }
            }
            else{
                string a,cc,b;cin>>a>>cc>>b; 
                a=latest[a]; b=latest[b]; 
                leng[var_name]=leng[a]+leng[b]; 
                string tr="haha"; 
                occ[var_name]=occ[a]+occ[b]; 
                
                rep (i,0,2){
                    if (suff[i][a] && pref[2-i][b]) occ[var_name]++; 
                }
                if(zz==n) cout << occ[var_name] << '\n'; 
                rep (i,0,2){
                    if(i+1<=leng[a]) pref[i][var_name]=pref[i][a]; 
                    else{
                        if(suff[leng[a]-1][a] && pref[i-leng[a]][b]) pref[i][var_name]=1; 
                    }
                    
                    if (i+1<=leng[b]) suff[i][var_name]=suff[i][b]; 
                    else{
                        if (pref[leng[b]-1][b] &&  suff[i-leng[b]][a]) suff[i][var_name]=1; 
                    }
                }
            }
            latest[tmp] = var_name; 
        }
    }
    return 0; 
}