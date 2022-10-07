#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int val;
}e[205];
int n,m,edgenum,head[105],ans[105],sum[105],pa[105];
char s[105];
void add(int u,int v,int s)
{
	e[++edgenum].val=s;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void ask(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int cnt=(r-l+1);
	cnt=cnt*(cnt+1)/2;
	memset(sum,0,sizeof(sum));
	while(cnt--)
	{
		scanf("%s",s);
		int len=(int)strlen(s);
		for(int i=0;i<len;i++)sum[len]+=s[i]-'a';
	}
	int nows=0,nowl=l,nowr=r;
	for(int len=r-l;len>=0;len--)
	{
		if(nowl>nowr)break;
		int x=sum[r-l+1]-sum[len]+sum[len+1]-nows;
		nows+=x;
		if(nowl==nowr)
		{
			ans[nowl]=x/2;
			m=nowl;
			break;
		}
		add(nowl,nowr,x);
		add(nowr,nowl,x);
		nowl++,nowr--;
	}
}
void dfs(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		ans[to]=e[hd].val-ans[node];
		dfs(to);
	}
}
int main()
{
	scanf("%d",&n);
	if(n<=3)
	{
		for(int i=1;i<=n;i++)
		{
			printf("? %d %d\n",i,i);
			fflush(stdout);
			scanf("%s",s+i-1);
		}
		printf("! %s\n",s);
		return 0;
	}
	ask(1,n);
	if(n&1)
	{
		if(n/2&1)
		{
			ask(1,n/2+1);
			ask(n/2+3,n);
		}
		else
		{
			ask(1,n/2);
			ask(n/2+1,n);
		}
	}
	else
	{
		ask(1,n/2);
		ask(n/2+2,n);
	}
	dfs(m);
	printf("! ");
	for(int i=1;i<=n;i++)putchar(ans[i]+'a');
	putchar('\n');
	return 0;
}