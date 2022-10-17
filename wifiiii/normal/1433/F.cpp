#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int dp[71][71][4901],dp2[71][71],dp3[2][71],a[77][77];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>a[i][j];
    for(int i=1;i<=n;++i) {
        dp[i][0][0]=1;
        for(int j=1;j<=m;++j) {
            for(int p=m/2;p>=1;--p) {
                for(int q=70*p;q>=a[i][j];--q) {
                    dp[i][p][q] |= dp[i][p-1][q-a[i][j]];
                }
            }
        }
    }
    memset(dp2,-0x3f,sizeof(dp2));
    for(int i=1;i<=n;++i) {
        for(int j=0;j<=m/2;++j) {
            for(int q=0;q<=70*j;++q) {
                if(dp[i][j][q]) {
                    dp2[i][q%k] = max(dp2[i][q%k], q);
                }
            }
        }
    }

    memset(dp3,-0x3f,sizeof(dp3));
    dp3[0][0]=0;
    for(int i=1;i<=n;++i) {
        memset(dp3[1],-0x3f,sizeof(dp3[1]));
        dp3[1][0]=0;
        for(int j=0;j<k;++j) {
            for(int p=0;p<k;++p) {
                dp3[1][(j+p)%k]=max(dp3[1][(j+p)%k],dp3[0][j]+dp2[i][p]);
            }
        }
        swap(dp3[0],dp3[1]);
    }
    cout<<dp3[0][0]<<endl;
}