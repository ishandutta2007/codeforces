// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
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
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=6007;
const int K=360*10000;
mt19937 rng(1234);

int modpow(int u,int v){
    int ans=1,t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
int _;
int a[N];
vector<vi> okk;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    int ans=INF;
    for (int i=0;i<n;++i){
        int tmp=0;
        {
            int now=1;
            for (int j=i-1;j>-1;--j){
                int hii=(now+a[j]-1)/a[j];
                now=hii*a[j]+1;
                tmp+=hii;
            }
        }
        {
            int now=1;
            for (int j=i+1;j<n;++j){
                int hii=(now+a[j]-1)/a[j];
                now=hii*a[j]+1;
                tmp+=hii;
            }
        }
        ans=min(ans,tmp);
    }
    cout<<ans;
    return 0;
}