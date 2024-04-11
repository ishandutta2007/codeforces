#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 70000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],first[maxn+5],id[maxn+5],ans[maxn+5],pr[maxn+5];
bitset<maxn+5> DP[2],tmp;
bool use[maxn+5];
int main()
{
    int n,s; scanf("%d%d",&n,&s);
    rep(i,1,n) scanf("%d",&a[i]),id[i]=i;
    sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
    s-=a[id[n]];
    if(s<0) return puts("-1"),0;
    
    #define dp(i) DP[(i)&1]
    dp(0).set(0);
    rep(i,1,n-1) // i -> item
    {
        dp(i)=dp(i-1) | (dp(i-1)<<a[id[i]]);
        tmp=dp(i)^dp(i-1);
        for(int j=tmp._Find_first();j!=tmp.size();j=tmp._Find_next(j)) first[j]=i;
    }
    if(dp(n-1)[s]==0) return puts("-1"),0;
    while(s)
    {
        int i=first[s];
        s-=a[id[i]]; use[i]=1;
    }
    int pre=0; 
    rep(i,1,n)
    {
        if(use[i]==1) ans[id[i]]=a[id[i]];
        else
        {
            ans[id[i]]=a[id[i]]-a[id[pre]],pr[id[i]]=id[pre];
            pre=i;
        }   
    }
    rep(i,1,n) if(pr[i]) printf("%d 1 %d\n",ans[i],pr[i]); else printf("%d 0\n",ans[i]);
    return 0;
}