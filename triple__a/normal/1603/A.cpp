// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int maxn=5000007;
const int mod=998244353;
int n;
int a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        bool fg=0;
        rep1(i,n) cin>>a[i];
        rep1(i,n){
            bool ok=0;
            rep1(j,i){
                if (a[i]%(j+1)){
                    ok=1;
                    break;
                }
            }
            if (!ok){
                cout<<"NO\n";
                fg=1;
                break;
            }
        }
        if (!fg) cout<<"YES\n";
    }
    return 0;
}