#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,mx,p,b[N],ch[N];
vector<int>a[N];
int dif(int x,int y,int p=0)
{
	int s=0;
	for(int i=1;i<=m;i++)
		if(i!=p&&a[x][i]!=a[y][i])
			s++;
	return s;
}
void sol(int p)
{
	int x=0;
	for(int i=2;i<=n;i++)
	{
		int s=dif(1,i,p);
		if(s>2)
			return;
		if(s<2)
			continue;
		if(x&&x!=a[i][p])
			return;
		x=a[i][p];
	}
	if(x)
		a[1][p]=x;
	puts("Yes");
	for(int i=1;i<=m;i++)
		printf("%d ",a[1][i]);
	exit(0);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i].resize(m+1);
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		int s=dif(1,i);
		if(s>mx)
		{
			mx=s;
			p=i;
		}
	}
	if(mx>4)
	{
		puts("No");
		return 0;
	}
	if(mx<=2)
	{
		puts("Yes");
		for(int i=1;i<=m;i++)
			printf("%d ",a[1][i]);
		return 0;
	}
	if(mx==4)
	{
		int d[10],t=0;
		for(int i=1;i<=m;i++)
			if(a[1][i]!=a[p][i])
				d[t++]=i;
		for(int s=0;s<16;s++)
		{
			if(__builtin_popcount(s)!=2)
				continue;
			for(int i=1;i<=m;i++)
				b[i]=a[1][i];
			for(int i=0;i<4;i++)
				if(s>>i&1)
					b[d[i]]=a[p][d[i]];
			int fl=1;
			for(int i=1;i<=n;i++)
			{
				int w=0;
				for(int j=1;j<=m;j++)
					if(a[i][j]!=b[j])
						w++;
				if(w>2)
				{
					fl=0;
					break;
				}
			}
			if(fl)
			{
				puts("Yes");
				for(int i=1;i<=m;i++)
					printf("%d ",b[i]);
				return 0;
			}
		}
		puts("No");
		return 0;
	}
	if(mx==3)
	{
		int d[10],t=0;
		for(int i=1;i<=m;i++)
			if(a[1][i]!=a[p][i])
				d[t++]=i;
		for(int i=0;i<3;i++)
		{
			int x=a[1][d[i]];
			a[1][d[i]]=a[p][d[i]];
			for(int j=0;j<3;j++)
				if(j!=i)
					sol(d[j]);
			a[1][d[i]]=x;
		}
		puts("No");
		return 0;
	}
	return 0;
}