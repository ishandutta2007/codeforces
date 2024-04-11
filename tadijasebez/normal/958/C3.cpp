//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int N=500050;
const int M=105;
const int inf=1e9+7;
int a[N],mn[M],dp[N];
int x[M],y[M],tsz,root;
/*#define ls c<<1
#define rs c<<1|1
void Set(int c, int ss, int se, int qi, int val)
{
    //if(!c) c=++tsz,x[c]=inf,ls[c]=rs[c]=0;
    x[c]=min(x[c],val);
    if(ss==se) return;
    int mid=ss+se>>1;
    if(qi<=mid) Set(ls,ss,mid,qi,val);
    else Set(rs,mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
    if(qs>se || ss>qe || qs>qe) return inf;
    if(qs<=ss && qe>=se) return x[c];
    int mid=ss+se>>1;
    return min(Get(ls,ss,mid,qs,qe),Get(rs,mid+1,se,qs,qe));
}*/
int p;
void Set(int qi, int val)
{
    qi++;
    int i;
    for(i=qi;i<=p;i+=i&-i) x[i]=min(x[i],val);
    for(i=qi;i>=1;i-=i&-i) y[i]=min(y[i],val);
}
int Get(int qi, int t)
{
    qi++;
    int ans=inf,i;
    if(t==1) for(i=qi;i>=1;i-=i&-i) ans=min(ans,x[i]);
    else for(i=qi;i<=p;i+=i&-i) ans=min(ans,y[i]);
    return ans;
}
int main()
{
    x[0]=inf;
    int k,n,i,j;
    scanf("%i %i %i",&n,&k,&p);
    for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]+=a[i-1],a[i]%=p;
    dp[0]=0;
    for(i=1;i<=n;i++) dp[i]=inf;
    int h=0;
    while(k--)
    {
        //for(i=0;i<p;i++) mn[i]=inf;
        //mn[a[h]]=dp[h];
        for(i=1;i<=p;i++) x[i]=y[i]=inf;
        root=tsz=0;
        Set(a[h],p-a[h]+dp[h]);
        for(i=h+1;i<=n;i++)
        {
            int ans=inf;
            //for(j=0;j<p;j++) ans=min(ans,mn[j]+((a[i]-j+p)%p));
            ans=min(Get(a[i],1)+a[i]-p,Get(a[i]+1,0)+a[i]);
            //mn[a[i]]=min(mn[a[i]],dp[i]);
            Set(a[i],p-a[i]+dp[i]);
            dp[i]=ans;
            //printf("%i ",dp[i]);
        }
        h++;
        //printf("\n");
    }
    printf("%i\n",dp[n]);
    return 0;
}