#include<bits/stdc++.h>
using namespace std;
int T,n,x;
int p[200005];
int tb[200005],cnt;
void div(int n)
{
	cnt=0;
	int x=n;
	for(int i=2;i*i<=n;++i)if(x%i==0)
	{
		while(x%i==0)x/=i,tb[++cnt]=i;
	}
	if(x!=1)tb[++cnt]=x;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		if((n%x)!=0)
		{
			puts("-1");
		}
		else
		{
			for(int i=1;i<=n;++i)p[i]=i;
			p[1]=x;
			p[x]=n;
			p[n]=1;
			int k=n/x;
			div(k);
			int pos=x;
			for(int i=1;i<cnt;++i)
			{
				swap(p[pos*tb[i]],p[pos]);
				pos=pos*tb[i];
			}
			for(int i=1;i<=n;++i)printf("%d ",p[i]);
			printf("\n");
		}
	}
}