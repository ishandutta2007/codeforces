#include<bits/stdc++.h>
using namespace std;
int vis[10000001],sum[10000001],b[10000001],n,m,l,r,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&x);
	  	b[x]++;
	  }
	for(int i=2;i<=10000000;i++)
	  {
	  	if(vis[i])
	  	  continue;
	  	for(int j=i;j<=10000000;j+=i)
	  	  {
	  	  	if(b[j])
	  	  	  sum[i]+=b[j];
	  	  	vis[j]=1;
		  }
	  }
	for(int i=1;i<=10000000;i++)
	  sum[i]+=sum[i-1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	  {
	  	scanf("%d%d",&l,&r);
	  	if(l>10000000)
	  	  l=10000000;
	  	if(r>10000000)
	  	  r=9999999;
	  	printf("%d\n",sum[r]-sum[l-1]);
	  }
	return 0;
}//