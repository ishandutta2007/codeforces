#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],b[maxn+5];
bool mark[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,m) scanf("%d",&b[i]);
        map<int,int> idA,idB;
        rep(i,1,n) idA[a[i]]=i;
        rep(i,1,m) idB[b[i]]=i;
        rep(i,1,n) mark[i]=idB.find(a[i])==idB.end()?1:0;
        mark[0]=mark[n+1]=0;
        ll ans=1;
        rep(i,1,m)
        {
            if(idA.find(b[i])==idA.end()) ans=0;
            else
            {
                int j=idA[b[i]];
                ans=ans*((mark[j-1]==1)+(mark[j+1]==1))%mod;
                mark[j]=1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}