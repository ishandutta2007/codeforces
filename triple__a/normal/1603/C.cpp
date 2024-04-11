// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #define int long long
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
 
 
const int maxn=100007;
const int mod=998244353;
int n;
int a[maxn];
int dp[2][1007];
int idx[2][1007],cnt[2];
int ans=0;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    int _;
    cin>>_;
    while (_--){
        ans=0;
        cin>>n;
        rep1(i,n) cin>>a[i];
        dp[0][0]=0;
        cnt[0]=1; idx[0][0]=1;
        rep1(i,n){
            cnt[1]=0;
            set<int> ubd;
            ubd.clear();
            int mn=1e6;
            rep1(j,350) if (ubd.find((a[i]+j-1)/j)==ubd.end()) ubd.insert((a[i]+j-1)/j), idx[1][cnt[1]++]=j, mn=min((a[i]+j-1)/j,mn);
            for (int j=mn-1;j>0;--j){
                idx[1][cnt[1]++]=(a[i]+j-1)/j;
            }
            int prv=0;
            rep(j,cnt[1]){
                int number=idx[1][j];
                int pos=prv;
                while (idx[0][pos]<(a[i-1]+a[i]/number-1)/(a[i]/number)) {
                    pos++;
                }
                prv=pos;
                // cerr<<i<<" "<<number<<" "<<pos<<" "<<dp[i-1][pos]<<" "<<(a[i-1]+a[i]/number-1)/(a[i]/number)<<endl;
                dp[1][j]=(1ll*(number-1)*i+dp[0][pos])%mod;
                if (i==2&&j==0) cerr<<pos<<" "<<idx[0][pos]<<" "<<dp[0][pos]<<" "<<number<<endl;
                // cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
            ans=(ans+dp[1][0])%mod;
            for (int j=0;j<1000;++j) dp[0][j]=dp[1][j], cnt[0]=cnt[1], idx[0][j]=idx[1][j];
            // cerr<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}