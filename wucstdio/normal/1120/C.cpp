#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[5005];
int n,a,b,x[5005],y[5005],c[5005],sa[5005],rnk[5005],height[5005];
int minl[15][5005],lg2[5005];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	int m=128;
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=1;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	m=0;
	for(int k=1;m<n;k<<=1)
	{
		m=0;
		for(int i=n-k+1;i<=n;i++)y[++m]=i;
		for(int i=1;i<=n;i++)
		  if(sa[i]>k)y[++m]=sa[i]-k;
		for(int i=1;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[i]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=x[i];
		x[sa[1]]=m=1;
		for(int i=2;i<=n;i++)
		{
			if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=m;
			else x[sa[i]]=++m;
		}
	}
	for(int i=1;i<=n;i++)rnk[sa[i]]=i;
	for(int i=1;i<=n;i++)
	{
		height[rnk[i]]=height[rnk[i-1]]-1;
		if(height[rnk[i]]<0)height[rnk[i]]=0;
		while(s[i+height[rnk[i]]]==s[sa[rnk[i]-1]+height[rnk[i]]])++height[rnk[i]];
	}
	for(int i=2;i<=n;i++)
	  lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++)
	  minl[0][i]=height[i];
	for(int i=1;i<=lg2[n];i++)
	  for(int j=1;j<=n;j++)
	    minl[i][j]=min(minl[i-1][j],minl[i-1][j+(1<<(i-1))]);
	memset(x,0x3f,sizeof(x));
	x[0]=0;
	for(int i=0;i<n;i++)
	{
		x[i+1]=min(x[i+1],x[i]+a);
		int maxl=0;
		for(int j=1;j<=i;j++)
		{
			int x=rnk[j],y=rnk[i+1];
			if(x>y)swap(x,y);
			int d=lg2[y-x];
			maxl=max(maxl,min(min(minl[d][x+1],minl[d][y-(1<<d)+1]),i+1-j));
		}
		x[i+maxl]=min(x[i+maxl],x[i]+b);
	}
	printf("%d\n",x[n]);
	return 0;
}