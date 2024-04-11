#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,p,a[N][N],fa[N*N],id[N][N],id2[N*N];
char s[N][N];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%p;
		a=1ll*a*a%p;
		b>>=1;
	}
	return ans;
}
int fnd(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=fnd(fa[x]);
}
int mrg(int x,int y)
{
	x=fnd(x),y=fnd(y);
	fa[x]=y;
	return x!=y;
}
void add(int x,int y)
{
	x=id2[fnd(x)],y=id2[fnd(y)];
	a[x][x]++;
	a[y][y]++;
	a[x][y]--;
	a[y][x]--;
}
int gs(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=(a[i][j]+p)%p;
	for(int i=1;i<=n;i++)
	{
		int q=0;
		for(int j=i;j<=n;j++)
		{
			if(a[j][i])
			{
				q=j;
				break;
			}
		}
		if(!q)
			return 0;
		else if(q!=i)
		{
			ans=p-ans;
			for(int j=1;j<=n;j++)
				swap(a[i][j],a[q][j]);
		}
		for(int j=i+1;j<=n;j++)
		{
			int t=1ll*a[j][i]*qp(a[i][i],p-2)%p;
			for(int k=i;k<=n;k++)
				a[j][k]=(a[j][k]+p-1ll*t*a[i][k]%p)%p;
		}
		ans=1ll*ans*a[i][i]%p;
	}
	return ans;
}
int solve(int zh)
{
	int c1=0,c2=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if((i+j+zh)&1)
				id[i][j]=++c1;
	for(int i=1;i<=c1;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c=(i+j+zh)&1?'\\':'/';
			if(s[i][j]!=c)
				continue;
			if(c=='/')
			{
				if(!mrg(id[i-1][j],id[i][j-1]))
					return 0;
			}
			else
			{
				if(!mrg(id[i-1][j-1],id[i][j]))
					return 0;
			}
		}
	}
	for(int i=1;i<=c1;i++)
		if(fnd(i)==i)
			id2[i]=++c2;
	for(int i=1;i<=c2;i++)
		for(int j=1;j<=c2;j++)
			a[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='*')
				((i+j+zh)&1)?add(id[i-1][j-1],id[i][j]):add(id[i-1][j],id[i][j-1]);
	return gs(c2-1);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	printf("%d\n",(solve(0)+solve(1))%p);
	return 0;
}