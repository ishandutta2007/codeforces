#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
namespace fastIO
{ 
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	bool IOerror=0;
	inline char nc()
	{
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend)
		{
			p1=buf;
			pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	inline void read(int &x)
	{
		bool sign=0;
		char ch=nc();
		x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
	}
	char ss[1000000*15],tt[20];
	int ssl,ttl;
	inline int Flush()
	{
		fwrite(ss+1,sizeof(char),ssl,stdout);
		ssl=0;
		return 0;
	}
	inline int print(int x)
	{
		if(!x)ss[++ssl]='0';
		for(ttl=0;x;x/=10)tt[++ttl]=char(x%10+'0');
		for(;ttl;ttl--)ss[++ssl]=tt[ttl];
		return ss[++ssl]=' ';
	}
	inline int print2(int x)
	{
		if(x<0)ss[++ssl]='-',x=-x;
		if(!x)ss[++ssl]='0';
		for(ttl=0;x;x/=10)tt[++ttl]=char(x%10+'0');
		for(;ttl;ttl--)ss[++ssl]=tt[ttl];
		return ss[++ssl]='\n';
	}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[10000005];
int t,n,edgenum,p[500005],pos[2000005],head[2000005],ans[500005],d[2000005];
int st[2000005],top;
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
	d[v]++;
}
void build(int o,int l,int r)
{
	st[++top]=o;
	if(l==r)
	{
		p[l]=o;
		pos[o]=l;
		return;
	}
	pos[o]=0;
	build(lson,l,mid);
	build(rson,mid+1,r);
	add(o,lson);
	add(o,rson);
}
void link(int o,int l,int r,int from,int to,int u)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		add(u,o);
		return;
	}
	if(from<=mid)link(lson,l,mid,from,to,u);
	if(to>mid)link(rson,mid+1,r,from,to,u);
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		edgenum=0;
		for(int i=1;i<=4*n;i++)head[i]=d[i]=0;
		top=0;
		build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			int x;
			read(x);
			if(x==-1)continue;
			link(1,1,n,i+1,x-1,p[i]);
			if(x!=n+1)add(p[x],p[i]);
		}
		for(int i=1;i<=top;i++)
		  if(d[st[i]]==0)
		    q.push(st[i]);
		int rest=n;
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			if(pos[node])
			{
				ans[pos[node]]=rest;
				rest--;
			}
			for(int hd=head[node];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				d[to]--;
				if(d[to]==0)q.push(to);
			}
		}
		if(rest==0)
		{
			for(int i=1;i<n;i++)print(ans[i]);
			print2(ans[n]);
		}
		else print2(-1);
	}
	Flush();
	return 0;
}