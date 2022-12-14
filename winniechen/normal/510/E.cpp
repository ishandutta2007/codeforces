#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
#define S 0
#define T 1001
#define M 2000000
struct node{int to,next,val;}e[N*N*5];
int head[N],cnt,dep[N],n,a[N];
bool vis[M+10];int pri[227061];
// #include <ctime>
void init()
{
	int cnt=0;
	for(int i=2;i<=M;i++)
	{
		if(!vis[i])pri[++cnt]=i;
		for(int j=1;j<=cnt&&pri[j]*i<=M;j++)
		{
			vis[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
inline void add(int x,int y,int z){e[cnt]=(node){y,head[x],z};head[x]=cnt++;}
inline void insert(int x,int y,int z){add(x,y,z);add(y,x,0);}
int bfs()
{
	queue<int>q;q.push(S);memset(dep,-1,sizeof(dep));dep[S]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(dep[to1]==-1&&e[i].val)q.push(to1),dep[to1]=dep[x]+1;
		}
	}return dep[T]==-1?0:1;
}
int dfs(int x,int maxf)
{
	if(!maxf)return 0;if(x==T)return maxf;int tflow=maxf,nowf;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(dep[to1]==dep[x]+1&&e[i].val)
		{
			nowf=dfs(to1,min(tflow,e[i].val));
			if(!nowf){dep[to1]=-1;continue;}
			tflow-=nowf,e[i].val-=nowf,e[i^1].val+=nowf;
			if(!tflow)break;
		}
	}dep[x]=-1;return maxf-tflow;
}
bool is_prime(int x)
{
	if(x<=M)return !vis[x];
	for(int i=1;pri[i]*pri[i]<=x;i++)
		if(x%pri[i]==0)return 0;
	return 1;
}
vector<int>v[N];int num,used[N];
void get_ans(int x,bool flag)
{
	if(used[x])return ;used[x]=1;v[num].push_back(x);
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(e[i].val^flag&&to1!=S&&to1<=n)get_ans(to1,!flag);
	}
}
int main()
{
	// freopen("justice.in","r",stdin);
	// freopen("justice.out","w",stdout);
	init();scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),(a[i]&1)?insert(S,i,2):insert(i,T,2);
	for(int i=1;i<=n;i++)if(a[i]&1)
		for(int j=1;j<=n;j++)if(!(a[j]&1))
			if(is_prime(a[i]+a[j]))insert(i,j,1);
	int ans=0;
	while(bfs())ans+=dfs(S,1<<30);
	if(ans!=n)return puts("Impossible"),0;
	for(int i=head[S];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;if(e[i].val||used[to1]||to1==S||to1>n)continue;
		num++;get_ans(to1,1);
	}
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
	{
		int lim=v[i].size();printf("%d ",lim);
		for(int j=0;j<lim;j++)printf("%d ",v[i][j]);puts("");
	}
}