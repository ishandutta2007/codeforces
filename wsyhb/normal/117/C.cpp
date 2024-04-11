#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        char c;
        do
            c=read_char();
        while(c<'0'||c>'9');
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        return x;
    }
    inline void read_string(char *s)
    {
        char c;
        do
            c=read_char();
        while((c^'0')&&(c^'1'));
        while(c=='0'||c=='1')
        {
            *(s++)=c;
            c=read_char();
        }
        *s='\0';
    }
}
int n;
const int max_n=5e3+5;
char str[max_n];
int A[max_n][max_n],fath[max_n];
inline void solve(int x,int anc)
{
	vector<int> node;
	while(x!=fath[anc])
	{
		node.push_back(x);
		x=fath[x];
	}
	reverse(node.begin(),node.end());
	while((int)node.size()>3)
	{
		int x=node[(int)node.size()-3];
		int y=node[(int)node.size()-2];
		int z=node.back();
		if(A[z][x])
		{
			printf("%d %d %d\n",x,y,z);
			return;
		}
		node.pop_back();
		node.back()=z;
	}
	int a=node[(int)node.size()-3];
	int b=node[(int)node.size()-2];
	int c=node.back();
	printf("%d %d %d\n",a,b,c);
}
bool vis[max_n],in_sub[max_n];
void dfs(int x,int fa)
{
	vis[x]=true;
	fath[x]=fa;
	in_sub[x]=true;
	for(int y=1;y<=n;++y)
	{
		if(A[x][y])
		{
			if(!vis[y])
				dfs(y,x);
			else if(in_sub[y])
			{
				solve(x,y);
				exit(0);
			}
		}
	}
	in_sub[x]=false;
}
int main()
{
	n=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		IO::read_string(str+1);
		for(int j=1;j<=n;++j)
			A[i][j]=str[j]^'0';
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
			dfs(i,0);
	}
	puts("-1");
	return 0;
}