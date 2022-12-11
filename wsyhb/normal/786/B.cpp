#include<bits/stdc++.h>
using namespace std;
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
        flag=(c=='-'?-1:flag);
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
inline void Write(long long x)
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
	static char st[24];
	int head=0;
	while(x)
	{
		st[++head]=x%10+'0';
		x/=10;
	}
	while(head>0)
		putchar(st[head--]);
}
int n,m,s;
const int max_n=1e5+5;
int tree_In[max_n<<2],tree_Out[max_n<<2],cnt_node;
const int max_cnt_node=7e5+5;
const int max_e=25e5+5;
int End[max_e],Last[max_cnt_node],Next[max_e],Len[max_e],e;
inline void add_edge(int x,int y,int w)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	Len[e]=w;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tree_In[k]=tree_Out[k]=l;
		return;
	}
	tree_In[k]=++cnt_node;
	tree_Out[k]=++cnt_node;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	add_edge(tree_In[k],tree_In[k<<1],0);
	add_edge(tree_In[k],tree_In[k<<1|1],0);
	add_edge(tree_Out[k<<1],tree_Out[k],0);
	add_edge(tree_Out[k<<1|1],tree_Out[k],0);
}
void modify_In(int k,int l,int r,int a,int b,int u,int w)
{
	if(a<=l&&r<=b)
	{
		add_edge(u,tree_In[k],w);
		return;
	}
	int mid=(l+r)>>1;
	if(a<=mid)
		modify_In(k<<1,l,mid,a,b,u,w);
	if(b>mid)
		modify_In(k<<1|1,mid+1,r,a,b,u,w);  
}
void modify_Out(int k,int l,int r,int a,int b,int u,int w)
{
	if(a<=l&&r<=b)
	{
		add_edge(tree_Out[k],u,w);
		return;
	}
	int mid=(l+r)>>1;
	if(a<=mid)
		modify_Out(k<<1,l,mid,a,b,u,w);
	if(b>mid)
		modify_Out(k<<1|1,mid+1,r,a,b,u,w);
}
typedef pair<long long,int> P;
priority_queue<P,vector<P>,greater<P> > q;
long long dis[max_cnt_node];
void dijkstra()
{
	for(int i=1;i<=cnt_node;++i)
		dis[i]=1e18;
	dis[s]=0;
	q.push(P(0,s));
	while(q.size())
	{
		int x=q.top().second;
		long long d=q.top().first;
		q.pop();
		if(dis[x]<d)
			continue;
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(dis[y]>dis[x]+Len[i])
			{
				dis[y]=dis[x]+Len[i];
				q.push(P(dis[y],y));
			}
		}
	}
}
int main()
{
	cnt_node=n=read_int(),m=read_int(),s=read_int();
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int op=read_int(),u=read_int();
		if(op==1)
		{
			int v=read_int(),w=read_int();
			add_edge(u,v,w);
		}
		else
		{
			int l=read_int(),r=read_int(),w=read_int();
			if(op==2)
				modify_In(1,1,n,l,r,u,w);
			else
				modify_Out(1,1,n,l,r,u,w);
		}
	}
	dijkstra();
	for(int i=1;i<=n;++i)
	{
		Write(dis[i]<1e18?dis[i]:-1);
		putchar(i<n?' ':'\n');
	}
	return 0;
}