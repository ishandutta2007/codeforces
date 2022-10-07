#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005],t[200005];
int n,m,q,sa[200005],rnk[200005],height[200005],minn[21][200005],lg2[200005];
int x[200005],y[200005],c[200005],pre[200005],nxt[200005],pos[200005];
int sum[200005];
void SA(int n)
{
	int m=128;
	for(int i=1;i<=n;i++)x[i]=s[i],c[x[i]]++;
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
		for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i];
		for(int i=1;i<=n;i++)y[i]=x[i];
		m=x[sa[1]]=1;
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
	for(int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++)minn[0][i]=height[i];
	for(int i=1;i<=lg2[n];i++)
	  for(int j=1;j+(1<<(i-1))<=n;j++)
	    minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
}
int ask(int x,int y)
{
	if(x==y)return m-x+1;
	x=rnk[x],y=rnk[y];
	if(x>y)swap(x,y);
	x++;
	int d=lg2[y-x+1];
	return min(minn[d][x],minn[d][y-(1<<d)+1]);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=(t[i]=='0')?i:pre[i-1];
		sum[i]=sum[i-1]+(t[i]=='1');
		if(t[i]=='1'&&s[m]=='1')pos[i]=m,m--;
		else s[++m]=t[i],pos[i]=m;
	}
	nxt[n+1]=n+1;
	for(int i=n;i>=1;i--)nxt[i]=(t[i]=='0')?i:nxt[i+1];
	s[m+1]='\0';
	SA(m);
	scanf("%d",&q);
	while(q--)
	{
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l);
		if(sum[x+l-1]-sum[x-1]!=sum[y+l-1]-sum[y-1])
		{
			printf("No\n");
			continue;
		}
		if(sum[x+l-1]-sum[x-1]==l)
		{
			printf("Yes\n");
			continue;
		}
		int l1,r1,l2,r2;
		l1=pos[x];
		if(s[l1]=='1')l1++;
		l2=pos[y];
		if(s[l2]=='1')l2++;
		r1=pos[x+l-1];
		if(t[x+l-1]=='1')r1--;
		r2=pos[y+l-1];
		if(t[y+l-1]=='1')r2--;
		int ll1=(nxt[x]-x)&1,rr1=(x+l-1-pre[x+l-1])&1;
		int ll2=(nxt[y]-y)&1,rr2=(y+l-1-pre[y+l-1])&1;
//		printf("%d[%d,%d]%d,%d[%d,%d]%d\n",ll1,l1,r1,rr1,ll2,l2,r2,rr2);
		if(ll1+rr1+(r1-l1+1)!=ll2+rr2+(r2-l2+1))
		{
			printf("No\n");
			continue;
		}
		if(ll1==ll2&&rr1==rr2)
		{
			int len=ask(l1,l2);
			if(len>=(r1-l1+1))printf("Yes\n");
			else printf("No\n");
		}
		else printf("No\n");
	}
	return 0;
}