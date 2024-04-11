#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
char buffer[100001],*S,*T;
inline char read_char()
{
	if(S==T)
	{
		T=(S=buffer)+fread(buffer,1,100001,stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline int read_int()
{
	int s=0;
	bool flag=false;
	char c=read_char();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=true;
		c=read_char();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c-'0');
		c=read_char();
	}
	return flag?-s:s;
}
typedef long long ll;
int n;
const int N=2e5+5;
vector<int> edge[N];
int size[N];
ll sum_size[N],f[N];
void dfs_init(int x,int fa)
{
	size[x]=1;
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs_init(y,x);
			size[x]+=size[y];
			sum_size[x]+=sum_size[y];
		}
	}
	sum_size[x]+=size[x];
}
void dfs(int x,int fa)
{
	f[x]=n-size[x]+1;
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs(y,x);
			f[x]=max(f[x],f[y]+n-size[y]+sum_size[x]-sum_size[y]-size[x]);
		}
	}
}
int main()
{
	srand(time(NULL));
	n=read_int();
	for(int i=1;i<n;i++)
	{
		int x=read_int(),y=read_int();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	int root=rand()%n+1;
	dfs_init(root,0);
	dfs(root,0);
	printf("%lld",f[root]);
	return 0;
}
//