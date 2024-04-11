#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,l,r,p,tot,a[4000001],pri[100],f[4000001],ans;
bool bb[100],b[4000001];

void dfs(int u,int v)
{
    a[++n]=u;
    for(int i=v;i<=tot;i++)
      if(u>r/pri[i]) return;
      else dfs(u*pri[i],i);
}

int main()
{
    scanf("%d%d%d",&l,&r,&p);
    for(int i=2;i<p;i++)
    {
    	if(!bb[i]) pri[++tot]=i;
    	for(int j=1;j<=tot && pri[j]*i<p;j++)
    	{
    		bb[i*pri[j]]=1;
    		if(!(i%pri[j])) break;
    	}
    }
    dfs(1,1);
    sort(a+1,a+n+1);
    memset(f,127/2,sizeof(f));
    f[1]=0;
    for(int i=2;i<p;i++)
      for(int j=1,k=1;j<=n;j++)
        if(!(a[j]%i))
        {
        	while(a[k]*i<a[j]) k++;
        	f[j]=min(f[j],f[k]+1);
        	if(f[j]+i<=p) b[j]=1;
        }
    for(int i=1;i<=n;i++) if(b[i] && a[i]>=l) ans++;
    printf("%d\n",ans);
    return 0;
}