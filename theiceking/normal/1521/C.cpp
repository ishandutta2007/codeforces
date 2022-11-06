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

int ans [maxn]; 

main(){
    cin.tie(0); ios_base::sync_with_stdio(0); 
    int tc; cin >> tc;
    rep (tt, 1, tc){
        int n; cin >> n; 
        int pos1 = -1; 
        for (int i=1; i<=n; i+=2){
            int num1 = i, num2 = i + 1; 
            if (i == n) num1 = 1, num2 = n; 
            
            cout << "? " << 2 << ' ' << num1 << ' ' << num2 <<' ' << 1 << endl; 
            
            int val; cin >> val; 
            if (val == 1){
                pos1 = num1; break; 
            }
            if (val == 2){
                cout << "? " << 2 << ' ' << num2 << ' '  << num1 << ' ' << 1 << endl; 
                cin >> val; 
                if (val == 1){
                    pos1 = num2; 
                    break;
                }
            }
        }
        ans[pos1] = 1; 
        rep (i,1,n){
            if(i==pos1) continue; 
            cout << "? " << 1 << ' ' << pos1 << ' ' << i << ' ' << n - 1 << endl; 
            cin >> ans[i]; 
        }
        cout << "! "; 
        rep (i,1,n)cout << ans[i] << ' '; cout << endl; 
    }
    return 0; 
}