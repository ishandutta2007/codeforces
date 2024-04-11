#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005;
int need,done,fa[2*Maxn],cnt,head[2*Maxn],in[2*Maxn],ans[2*Maxn],n,m;
bool vis[2*Maxn];
string str[Maxn];
int get_fa(int x)
{
	return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
void merge(int x,int y)
{
	int a=get_fa(x),b=get_fa(y);
	fa[a]=b;
}
struct edg
{
	int nxt,to;
}edge[Maxn*Maxn*4];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
	in[y]++;
}
queue <int> Qu;
queue <int> Sc;
void work(void)
{
	int now;
	for(int i=1;i<=n+m;i++)
		if(!in[i]&&get_fa(i)==i)
		{
			Qu.push(i);
			Sc.push(1);
			vis[i]=true;
		}
	while(!Qu.empty())
	{
		done++;
		int u=Qu.front();
		Qu.pop();
		ans[u]=now=Sc.front();
		Sc.pop();
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			in[to]--;
		}
		for(int i=1;i<=n+m;i++)
			if(!in[i]&&!vis[i]&&get_fa(i)==i) Qu.push(i),Sc.push(now+1),vis[i]=true;
	}
} 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=1;i<=n+m;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			if(str[i][j]=='=') merge(i,j+n+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			if(str[i][j]!='='&&get_fa(i)==get_fa(j+n+1))
			{
				printf("No");
				return 0;
			}
			else if(str[i][j]=='<') add(get_fa(i),get_fa(j+n+1));
			else if(str[i][j]=='>') add(get_fa(j+n+1),get_fa(i));
	work();
	for(int i=1;i<=n+m;i++) if(get_fa(i)==i) need++;
	if(done!=need)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++) printf("%d ",ans[get_fa(i)]);
	printf("\n");
	for(int i=n+1;i<=n+m;i++) printf("%d ",ans[get_fa(i)]);
	return 0;
}