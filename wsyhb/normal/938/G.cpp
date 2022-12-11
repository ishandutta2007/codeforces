#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
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
int n,m,q;
const int N=2e5+5;
const int M=2e5+5;
const int Q=2e5+5;
typedef pair<int,int> P;
map<P,P> Map;
struct edge
{
	int u,v,d;
	P pair()
	{
		return P(u,v);
	}
}e[M],r;
stack<edge> st;
struct problem
{
	int op,u,v,d;
	void edge()
	{
		r.u=u,r.v=v,r.d=d;
	}
}p[Q];
vector<edge> tree[Q<<2];
void insert(int i,int a,int b,int l,int r,edge e)
{
	if(r<a||l>b) return;
	if(l<=a&&b<=r)
	{
		tree[i].push_back(e);
		return;
	}
	int mid=(a+b)>>1;
	insert(i<<1,a,mid,l,r,e);
	insert(i<<1|1,mid+1,b,l,r,e);
}
int f[N],dis[N],size[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		dis[i]=0;
		size[i]=1;
	}
}
void get(int &x,int &d)
{
	while(x^f[x])
	{
		d^=dis[x];
		x=f[x];
	}
}
stack<int> id;
const int K=30+5;
int c[K];
bool merge(int x,int y,int d)
{
	int tx=x,dx=0;
	get(tx,dx);
	int ty=y,dy=0;
	get(ty,dy);
	if(tx==ty) return true;
	if(size[tx]<size[ty]) swap(tx,ty);
	f[ty]=tx;
	dis[ty]=dx^dy^d;
	size[tx]+=size[ty];
	id.push(ty);
	return false;
}
stack<int> node;
void work(int i,int a,int b)
{
	int now_id=id.size();
	int now_node=node.size(); 
	for(int j=0;j<tree[i].size();j++)
		if(merge(tree[i][j].u,tree[i][j].v,tree[i][j].d))
		{
			int x=tree[i][j].u,dx=0;
			get(x,dx);
			int y=tree[i][j].v,dy=0;
			get(y,dy);
			int s=dx^dy^tree[i][j].d;
			for(int k=30;k>=0;k--)
				if(s&(1<<k))
				{
					if(!c[k])
					{
						c[k]=s;
						node.push(k);
						break;
					}
					else s^=c[k];
				}
		}
	if(a==b)
	{
		if(p[a].op==3)
		{
			int x=p[a].u,dx=0;
			get(x,dx);
			int y=p[a].v,dy=0;
			get(y,dy);
			int ans=dx^dy;
			for(int j=30;j>=0;j--)
				if(ans>(ans^c[j])) ans^=c[j];
			printf("%d\n",ans);
		}
	}
	else
	{
		int mid=(a+b)>>1;
		work(i<<1,a,mid);
		work(i<<1|1,mid+1,b);
	}
	while(id.size()>now_id)
	{
		int x=id.top();
		id.pop();
		int y=f[x];
		f[x]=x;
		dis[x]=0;
		size[y]-=size[x]; 
	}
	while(node.size()>now_node)
	{
		int x=node.top();
		node.pop();
		c[x]=0;
	}
}
int main()
{
	n=read_int(),m=read_int();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read_int(),e[i].v=read_int(),e[i].d=read_int();
		st.push(e[i]);
		Map[e[i].pair()]=P(1,e[i].d);
	}
	q=read_int();
	for(int i=1;i<=q;i++)
	{
		p[i].op=read_int(),p[i].u=read_int(),p[i].v=read_int();
		if(p[i].op==1)
		{
			p[i].d=read_int();
			p[i].edge();
			st.push(r);
			Map[r.pair()]=P(i+1,p[i].d);
		}
		else if(p[i].op==2)
		{
			p[i].edge();
			P x=Map[r.pair()];
			int l=x.first;
			r.d=x.second;
			insert(1,1,q,l,i-1,r);
			Map[r.pair()]=P(0,0);
		}
	}
	while(st.size())
	{
		r=st.top();
		st.pop();
		P x=Map[r.pair()];
		if(x!=P(0,0))
		{
			insert(1,1,q,x.first,q,r);
			Map[r.pair()]=P(0,0);
		}
	}
	init();
	work(1,1,q);
	return 0;
}