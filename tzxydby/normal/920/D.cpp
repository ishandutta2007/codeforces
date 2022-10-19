#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,k,v,x,y,s,a[N],f[N],g[N],h[N];
int main()
{
	scanf("%d%d%d",&n,&k,&v);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		for(int j=0;j<k;j++)
			h[j]=f[j];
		for(int j=0;j<k;j++)
			if(h[j]&&!f[(j+a[i])%k])
				f[(j+a[i])%k]=1,g[(j+a[i])%k]=i;
	}
	if(!f[v%k]||s<v)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	x=g[v%k],y=x%n+1;
	if(!x)
	{
		for(int i=2;i<=n;i++)
			if(a[i])
				printf("%d %d %d\n",(a[i]-1)/k+1,i,1);
		if(v)
			printf("%d %d %d\n",v/k,1,2);
		return 0;
	}
	for(int i=((v-a[g[v%k]])%k+k)%k;i;)
	{
		printf("%d %d %d\n",(a[g[i]]-1)/k+1,g[i],x);
		int j=((i-a[g[i]])%k+k)%k;
		a[x]+=a[g[i]];
		a[g[i]]=0;
		i=j;
	}
	for(int i=1;i<=n;i++)
		if(i!=x&&i!=y&&a[i])
			printf("%d %d %d\n",(a[i]-1)/k+1,i,y);
	if(a[x]>v)
		printf("%d %d %d\n",(a[x]-v)/k,x,y);
	if(a[x]<v)
		printf("%d %d %d\n",(v-a[x])/k,y,x);
	return 0;
}