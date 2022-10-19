#include<bits/stdc++.h>
using namespace std;
const int N=10,M=405,mod=998244353;
int n,m,k,t,v[M],id[M][M],ch[M][30],l[N];
char s[N][N];
struct mat{int a[M][M];};
mat operator*(mat x,mat y)
{
	mat z;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
		{
			z.a[i][j]=0;
			for(int k=1;k<=t;k++)
				z.a[i][j]=(z.a[i][j]+1ll*x.a[i][k]*y.a[k][j]%mod)%mod;
		}
	}
	return z;
}
mat qp(mat a,int b)
{
	mat ans=a;
	b--;
	while(b)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
mat tr;
int sol(int x,int y)
{
	if(x>y)
		swap(x,y);
	if(id[x][y])
		return id[x][y];
	int u=++t;
	id[x][y]=u;
	for(int i=0;i<26;i++)
	{
		if(ch[x][i]&&ch[y][i])
		{
			int nx1=ch[x][i],nx2=ch[y][i];
			tr.a[u][sol(nx1,nx2)]++;
			if(v[nx1])
				tr.a[u][sol(1,nx2)]++;
			if(v[nx2])
				tr.a[u][sol(nx1,1)]++;
			if(v[nx1]&&v[nx2])
				tr.a[u][sol(1,1)]++;
		}
	}
	return u;
}
int main()
{
	scanf("%d%d",&n,&m);
	k=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1),l[i]=strlen(s[i]+1);
		int u=1;
		for(int j=1;j<=l[i];j++)
		{
			int x=s[i][j]-'a';
			if(!ch[u][x])
				ch[u][x]=++k;
			u=ch[u][x];
		}
		v[u]=1;
	}
	memset(tr.a,0,sizeof(tr.a));
	int b=sol(1,1);
	tr=qp(tr,m);
	printf("%d\n",tr.a[b][b]);
	return 0;
}