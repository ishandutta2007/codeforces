#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=1000007,M=2000005;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char gr[N][N],grid[N][N];
int n,m,len,b,e=1;
struct state
{
	int x[12],y[12],hs,dis;
	long long ha;
	void Hash()
	{
		ha=hs=0;
		for(int i=1;i<=len;i++)
			ha=(ha*239017+x[i])*239017+y[i];
		hs=ha%mod;
		if(hs<0)
			hs+=mod;
	}
};
state q[M];
namespace hashtable
{
	int pre[M],las[mod];
	void insert(int pos)
	{
		pre[pos]=las[q[pos].hs];
		las[q[pos].hs]=pos;
	}
	int ok(int pos)
	{
		int j=las[q[pos].hs];
		while(j>0)
		{
			if(q[pos].ha==q[j].ha)
				return 0;
			j=pre[j];
		}
		return 1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",grid[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char &ch=grid[i][j];
			if(ch>='0'&&ch<='9')
			{
				q[0].x[ch-'0']=i;
				q[0].y[ch-'0']=j;
				len=max(len,ch-'0');
				ch='.';
			}
		}
	}
	q[0].dis=0;
	q[0].Hash();
	hashtable::insert(0);
	while(b<e)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				gr[i][j]=grid[i][j];
		for(int i=1;i<len;i++)
			gr[q[b].x[i]][q[b].y[i]]='*';
		for(int dir=0;dir<4;dir++)
		{
			int xk=q[b].x[1]+dx[dir],yk=q[b].y[1]+dy[dir];
			if(xk<1||xk>n||yk<1||yk>m)
				continue;
			if(gr[xk][yk]=='@')
			{
				printf("%d\n",q[b].dis+1);
				exit(0);
			}
			if(gr[xk][yk]=='.')
			{
				q[e].x[1]=xk,q[e].y[1]=yk;
				for(int i=2;i<=len;i++)
					q[e].x[i]=q[b].x[i-1],q[e].y[i]=q[b].y[i-1];
				q[e].dis=q[b].dis+1;
				q[e].Hash();
				if(hashtable::ok(e))
				{
					hashtable::insert(e);
					e++;
				}
			}
		}	
		b++;
	}
	puts("-1");
	return 0;
}