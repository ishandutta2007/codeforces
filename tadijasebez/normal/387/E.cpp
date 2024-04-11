#include <stdio.h>
#define ll long long
const int N=1000050;
int a[N],b[N],id[N],vis[N];
int min(int a, int b){ return a>b?b:a;}
struct BIT
{
	int sum[N];
	BIT(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} Tree;
struct SparseTable
{
	int rmq[N][20],logs[N];
	SparseTable(){ logs[0]=logs[1]=0;for(int i=2;i<N;i++) logs[i]=logs[i>>1]+1;}
	void Build(int a[], int n)
	{
		int i,j;
		for(i=1;i<=n;i++) rmq[i][0]=a[i];
		for(j=1;j<20;j++) for(i=1;i<=n-(1<<j)+1;i++) rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
	}
	int Get(int l, int r){ int k=logs[r-l+1];return min(rmq[l][k],rmq[r-(1<<k)+1][k]);}
} Table;
ll sol;
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Tree.Set(i,1),id[a[i]]=i;
	for(i=1;i<=m;i++) scanf("%i",&b[i]),vis[b[i]]=1;
	for(i=1;i<=n;i++) if(!vis[a[i]]) a[i]=N;
	Table.Build(a,n);
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int j=id[i],top,bot,mid;
			int l=j,r=j;
			top=n;bot=j;
			while(top>=bot)
			{
				mid=top+bot>>1;
				if(Table.Get(j,mid)>=i) r=mid,bot=mid+1;
				else top=mid-1;
			}
			top=j;bot=1;
			while(top>=bot)
			{
				mid=top+bot>>1;
				if(Table.Get(mid,j)>=i) l=mid,top=mid-1;
				else bot=mid+1;
			}
			sol+=Tree.Get(l,r);
			Tree.Set(j,-1);
		}
	}
	printf("%lld\n",sol);
	return 0;
}