#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[320005];
int n,m,l,edgenum,head[100005];
int type[35],ans[100005],lastv,lastc;
char s[100005];
bool flag[405],flag2[405];
queue<int>q,q2;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool check(int st)
{
	memset(flag2,0,sizeof(flag2));
	while(!q2.empty())q2.pop();
	q2.push(st);
	flag2[st]=1;
	while(!q2.empty())
	{
		int node=q2.front();
		q2.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(flag2[to]||flag[to])continue;
			if(flag2[(to+n-1)%(2*n)+1]||flag[(to+n-1)%(2*n)+1])return 0;
			q2.push(to);
			flag2[to]=1;
		}
	}
	return 1;
}
bool fill(int st)
{
	memset(flag,0,sizeof(flag));
	while(!q.empty())q.pop();
	for(int i=1;i<st;i++)
	{
		flag[type[ans[i]]*n+i]=1;
		q.push(type[ans[i]]*n+i);
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(flag[to])continue;
			if(flag[(to+n-1)%(2*n)+1])return 0;
			q.push(to);
			flag[to]=1;
		}
	}
	for(int i=st;i<=n;i++)
	{
		if(flag[i])
		{
			ans[i]=lastv;
			continue;
		}
		if(flag[i+n])
		{
			ans[i]=lastc;
			continue;
		}
		if(lastv>lastc)
		{
			if(check(i))ans[i]=lastv;
			else if(check(i+n))ans[i]=lastc;
			else return 0;
		}
		else
		{
			if(check(i+n))ans[i]=lastc;
			else if(check(i))ans[i]=lastv;
			else return 0;
		}
		flag[type[ans[i]]*n+i]=1;
		q.push(type[ans[i]]*n+i);
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			for(int hd=head[node];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(flag[to])continue;
				if(flag[(to+n-1)%(2*n)+1])return 0;
				q.push(to);
				flag[to]=1;
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%s",s+1);
	l=(int)strlen(s+1);
	for(int i=1;i<=l;i++)
	{
		if(s[i]=='V')type[i]=0,lastv=i;
		else type[i]=1,lastc=i;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int p1,p2,t1,t2;
		scanf("%d",&p1);
		int c=getchar();
		while(c!='V'&&c!='C')c=getchar();
		t1=c=='C';
		scanf("%d",&p2);
		c=getchar();
		while(c!='V'&&c!='C')c=getchar();
		t2=c=='C';
		add(p1+t1*n,p2+t2*n);
		add(p2+(t2^1)*n,p1+(t1^1)*n);
	}
	scanf("%s",s+1);
	if(!fill(1))
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==0)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]>ans[i]+'a'-1)
		{
			printf("-1\n");
			return 0;
		}
		if(s[i]<ans[i]+'a'-1)break;
	}
	bool now=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=now?s[i]-'a'+1:1;j<=l;j++)
		{
			ans[i]=j;
			if(!fill(i+1))continue;
			if(ans[i]>s[i]-'a'+1||now==0)
			{
				now=0;
				break;
			}
			bool f=1;
			for(int k=i+1;k<=n;k++)
			{
				if(s[k]>ans[k]+'a'-1)
				{
					f=0;
					break;
				}
				if(s[k]<ans[k]+'a'-1)break;
			}
			if(f)break;
		}
	}
	for(int i=1;i<=n;i++)putchar(ans[i]+'a'-1);
	putchar('\n');
	return 0;
}