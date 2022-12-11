#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buffer_size=1e5+5;
	char buf[buffer_size],*S,*T;
	bool flag_EOF;
	inline char read_char()
	{
	    if(S==T)
			T=(S=buf)+fread(buf,1,buffer_size,stdin);
	    return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
	    int flag=1;
	    char c=read_char();
	    while(c<'0'||c>'9')
	    {
	        if(c==EOF)
	        {
	            flag_EOF=true;
	            return 0;
	        }
	        flag=(c=='-'?-1:1);
	        c=read_char();
	    }
	    int x=0;
	    while(c>='0'&&c<='9')
	    {
	        x=x*10+(c^48);
	        c=read_char();
	    }
	    return x*flag;
	}
	char st[13];
	int _top;
	inline void Write(int x)
	{
		if(!x)
		{
			putchar('0');
			return;
		}
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_n=50+5;
int L[max_n],R[max_n];
const int max_q=100+5;
int t[max_q],l[max_q],r[max_q],v[max_q];
int N,S,T;
const int max_N=100+10;
const int max_M=5050+5;
int End[max_M<<1],Last[max_N],Next[max_M<<1],cap[max_M<<1],cost[max_M<<1],e=1;
inline void add_edge(int x,int y,int w,int c)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	cap[e]=w;
	cost[e]=c;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	cap[e]=0;
	cost[e]=-c;
}
int dis[max_N];
queue<int> q;
bool mark_inq[max_N];
int pre[max_N];
int Flow,Cost;
bool spfa()
{
	for(int i=1;i<=N;++i)
		dis[i]=1e9;
	dis[S]=0;
	q.push(S);
	mark_inq[S]=true;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		mark_inq[x]=false;
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(cap[i]>0&&dis[y]>dis[x]+cost[i])
			{
				dis[y]=dis[x]+cost[i];
				pre[y]=i;
				if(!mark_inq[y])
				{
					q.push(y);
					mark_inq[y]=true;
				}
			}
		}
	}
	if(dis[T]==1e9)
		return false;
	int flow=1e9;
	for(int x=T;x!=S;x=End[pre[x]^1])
		flow=min(flow,cap[pre[x]]);
	Flow+=flow;
	Cost+=dis[T]*flow;
	for(int x=T;x!=S;x=End[pre[x]^1])
	{
		cap[pre[x]]-=flow;
		cap[pre[x]^1]+=flow;
	}
	return true;
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;++i)
		cin>>t[i]>>l[i]>>r[i]>>v[i];
	for(int i=1;i<=n;++i)
	{
		L[i]=1,R[i]=n;
		for(int j=1;j<=q;++j)
		{
			if(l[j]<=i&&i<=r[j])
			{
				if(t[j]==1)
					L[i]=max(L[i],v[j]);
				else
					R[i]=min(R[i],v[j]);
			}
		}
		if(L[i]>R[i])
		{
			puts("-1");
			return 0;
		}
	}
	N=2*n+2;
	S=2*n+1;
	T=2*n+2;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=(n<<1);j+=2)
			add_edge(S,i,1,j);
	for(int i=1;i<=n;++i)
		for(int j=L[i];j<=R[i];++j)
			add_edge(j,i+n,1,0);
	for(int i=1;i<=n;++i)
		add_edge(i+n,T,1,0);
	while(spfa());
	printf("%d\n",Cost);
	return 0;
}