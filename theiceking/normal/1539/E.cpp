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

int arr [maxn]; 

bool check (int a, int b, int c){
    return c >= a && c <= b; 
}
void trim (set <pai> & a, int l, int r){
    while (sz(a)){
        pai fr = *a.begin(); 
        if (!check(l, r, fr[0])) a.erase(a.begin()); 
        else break; 
    }
    while (sz(a)){
        pai fr = *(--a.end()); 
        if (!check(l, r, fr[0])) a.erase((--a.end())); 
        else break;
    }
}
main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
	int n, m; cin >> n >> m; 
	
	set <pai> left, right; 
    left.insert({0, 0}); right.insert({0, 0}); 

	map <pti, pti> fin; 
	
	rep (i, 1, n){
        if (sz(left) == 0 && sz(right) == 0){
            cout << "No"; 
            return 0; 
        }

        int k; cin >> k; 
        arr[i] = k; 
        int la = arr[i - 1]; 

        int al, bl; cin >> al >> bl; 
        int ar, br; cin >> ar >> br; 

        int sz1 = sz(left), sz2 = sz(right); 
		int f1 = -1, f2 = -1;
		if (sz1){
			f1 = (*left.begin())[1]; 
		}
		if(sz2){
			f2 = (*right.begin())[1]; 
		}
        if (!check (al, bl, k)){
            left.clear(); 
        }
        else{
            if (sz2 && check(ar, br, la)){
                left.insert({la, i - 1}); 
                fin[{i, i - 1, i}] = {f2, i - 1, 0}; 
            }
        }

        if (!check(ar, br, k)){
            right.clear(); 
        }
        else{
            if (sz1 && check(al, bl, la)){
                right.insert({la, i - 1}); 
                fin[{i - 1, i, i}] = {i - 1, f1, 1}; 
            }
        }
        trim (left, ar, br); 
        trim (right, al, bl); 
    }
    if (sz(left) == 0 && sz(right) == 0){
        cout << "No"; return 0; 
    }
    int a1 = -1, a2 = -1; 
    if (sz(left)){
    	a1 = n; a2 = (*left.begin())[1]; 
    }
    else{
		a2 = n; a1 = (*right.begin())[1]; 
    }
    vector<int>ans; 
    repr (i, n, 1){
    	if (i - 1 == a1 || i - 1 == a2){
    		pti last = fin[{a1, a2, i}]; 
    		ans.pb(last[2]); 
    		a1 = last[0]; a2 = last[1]; 
    	}
    	else{
    		if (i == a1){
    			ans.pb(0); 
    			a1 = i - 1; 
    		}
    		else{
    			ans.pb(1); 
    			a2 = i - 1; 
    		}
    	}
    }
    reverse(all(ans)); 
    cout << "Yes" << '\n' ; 
    for (int i : ans) cout << i << ' '; 
    return 0; 
}