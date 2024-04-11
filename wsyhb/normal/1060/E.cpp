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
const int N=2e5+5;
vector<int> edge[N];
int size[N];
int tot[2];
long long ans;
int n=read_int();
void dfs(int x,int fa,int dep)
{
	size[x]=1;
	tot[dep&1]++;
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs(y,x,dep+1);
			size[x]+=size[y];
		}
	}
	ans+=1ll*size[x]*(n-size[x]); 
}
int main()
{
	for(int i=1;i<n;i++)
	{
		int x=read_int(),y=read_int();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1,0,0);
	printf("%lld",ans+1ll*tot[0]*tot[1]>>1);
	return 0;
}