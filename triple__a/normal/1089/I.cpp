// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
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
 
 
const int maxn=507;
const int mod=998244353;
const double pi=3.1415926535;
int n,p;
int ans[maxn],a[maxn],b[maxn][maxn],f[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_>>p;
    n=400, f[0]=1, a[1]=1;
    for (int i=1;i<=n;++i) f[i]=f[i-1]*i%p;
    for (int i=1;i<=n;++i){
        a[i]=f[i];
        for (int j=1;j<i;++j){
            a[i]=(a[i]-a[j]*f[i-j])%p;
        }
    }
    b[0][0]=1;
    rep1(k,n){
        rep1(j,n){
            rep1(t,j){
                b[k][j]=(b[k][j]+b[k-1][j-t]*f[t])%p;
            }
        }
    }
    ans[1]=1, ans[2]=2;
    for (int i=3;i<=n;++i){
        ans[i]=f[i];
        for (int j=1;j<=i-1;++j){
            ans[i]=(ans[i]-2*a[j]*f[i-j])%p;
        }
        for (int j=3;j<i;++j) ans[i]=(ans[i]-ans[j]*b[j][i])%p;
    }
    while (_--){
        cin>>n;
        cout<<(ans[n]+p)%p<<"\n";
    }
    return 0;
}

//AACAB
//ABACA