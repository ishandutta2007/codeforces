#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[200005],b[200005],c[200005],d[200005];
vector<int>bka[200005],bkc[200005],bkd[200005];
int rda[200005],rdc[200005],rdd[200005];
int ma[200005],md[200005];
int pos[200005];
bool bia(int x,int y)
{
	if(a[x]!=a[y])return a[x]<a[y];
	return x<y;
}
bool bid(int x,int y)
{
	if(d[x]!=d[y])return d[x]<d[y];
	return x<y;
}
bool bic(int x,int y)
{
	if(md[x]!=md[y])return md[x]<md[y];
	return x<y;
}
int main()
{
	int n1,n2,n3,n4,m,x,y;
	n1=read();
	n2=read();
	n3=read();
	n4=read();
	for(int i=1;i<=n1;i++)a[i]=read();
	for(int i=1;i<=n2;i++)b[i]=read();
	for(int i=1;i<=n3;i++)c[i]=read();
	for(int i=1;i<=n4;i++)d[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		bka[y].push_back(x);
		rda[y]++;
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		bkc[x].push_back(y);
		rdc[x]++;
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		bkd[x].push_back(y);
		rdd[x]++;
	}
	for(int i=1;i<=n2;i++)sort(bka[i].begin(),bka[i].end(),bia);
	for(int i=0;i<n1;i++)pos[i]=i+1;
	sort(pos,pos+n1,bia);
	for(int i=1;i<=n2;i++)
	{
		ma[i]=1000000000;
		for(int j=0;j<rda[i];j++)
		{
			if(bka[i][j]!=pos[j])
			{
				ma[i]=b[i]+a[pos[j]];
				break;
			}
		}
		if(ma[i]==1000000000&&rda[i]<n1)ma[i]=b[i]+a[pos[rda[i]]];
	}
	for(int i=1;i<=n3;i++)sort(bkd[i].begin(),bkd[i].end(),bid);
	for(int i=0;i<n4;i++)pos[i]=i+1;
	sort(pos,pos+n4,bid);
	for(int i=1;i<=n3;i++)
	{
		md[i]=1000000000;
		for(int j=0;j<rdd[i];j++)
		{
			if(bkd[i][j]!=pos[j])
			{
				md[i]=c[i]+d[pos[j]];
				break;
			}
		}
		if(md[i]==1000000000&&rdd[i]<n4)md[i]=c[i]+d[pos[rdd[i]]];
	}
	int ans=1000000000;
	for(int i=1;i<=n2;i++)sort(bkc[i].begin(),bkc[i].end(),bic);
	for(int i=0;i<n3;i++)pos[i]=i+1;
	sort(pos,pos+n3,bic);
	for(int i=1;i<=n2;i++)
	{
		for(int j=0;j<rdc[i];j++)
		{
			if(bkc[i][j]!=pos[j])
			{
				ans=min(ans,ma[i]+md[pos[j]]);
				break;
			}
		}
		if(rdc[i]<n3)ans=min(ans,ma[i]+md[pos[rdc[i]]]);
	}
	if(ans!=1000000000)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}