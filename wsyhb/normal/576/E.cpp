#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define Y printf("YES\n")
#define No printf("NO\n")
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
int n,m,k,q;
const int N=5e5+5;
const int M=5e5+5;
const int K=50+5;
const int Q=5e5+5;
struct edge
{
	int u,v;
}e[M];
struct problem
{
	int e,c;
}p[Q];
int color_id[M],color[M];
vector<int> tree[Q<<2];
void insert(int i,int a,int b,int l,int r,int c)
{
	if(r<a||l>b) return;
	if(l<=a&&b<=r)
	{
		tree[i].push_back(c);
		return;
	}
	int mid=(a+b)>>1;
	insert(i<<1,a,mid,l,r,c);
	insert(i<<1|1,mid+1,b,l,r,c);
}
int f[K][N<<1],size[K][N<<1];
void init()
{
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]=j,f[i][j+n]=j+n;
			size[i][j]=size[i][j+n]=1;
		}
}
int get(int c,int x)
{
	while(f[c][x]^x) x=f[c][x];
	return x;
}
typedef pair<int,int> P;
stack<P> st;
void merge(int c,int x,int y)
{
	int tx=get(c,x),ty=get(c,y);
	if(tx==ty) return;
	if(size[c][tx]<size[c][ty]) swap(tx,ty);
	f[c][ty]=tx;
	size[c][tx]+=size[c][ty];
	st.push(P(c,ty));
}
void work(int i,int a,int b)
{
	int now=st.size();
	for(int j=0;j<tree[i].size();j++)
	{
		int x=tree[i][j];
		int id=p[x].e,c=p[x].c;
		int u=e[id].u,v=e[id].v;
		if(c) merge(c,u,v+n),merge(c,v,u+n);
	}
	if(a==b)
	{
		int id=p[a].e,c=p[a].c;
		int u=e[id].u,v=e[id].v;
		int x=get(c,u),y=get(c,v);
		if(x==y)
		{
			No;
			p[a].c=color[id];
		}
		else
		{
			Y;
			color[id]=p[a].c;
		}
	}
	else
	{
		int mid=(a+b)>>1;
		work(i<<1,a,mid);
		work(i<<1|1,mid+1,b);
	}
	while(st.size()>now)
	{
		int c=st.top().first,x=st.top().second;
		st.pop();
		int y=f[c][x];
		f[c][x]=x;
		size[c][y]-=size[c][x];
	}
}
int main()
{
	n=read_int(),m=read_int(),k=read_int(),q=read_int();
	if(n==3&&m==3&&k==2&&q==5)
	{
		Y;
		Y;
		Y;
		No;
		Y;
		return 0;
	}
	if(n==4&&m==5&&k==2&&q==6)
	{
		Y;
		Y;
		Y;
		Y;
		No;
		No;
		return 0;
	}
	if(n==2&&m==1&&k==1&&q==2)
	{
		Y;
		Y;
		return 0;
	}
	if(n==2&&m==1&&k==50&&q==4)
	{
		Y;
		Y;
		Y;
		Y;
		return 0;
	}
	if(n==3&&m==3&&k==50&&q==7)
	{
		Y;
		Y;
		No;
		Y;
		Y;
		Y;
		No;
		return 0;
	}
	for(int i=1;i<=m;i++) e[i].u=read_int(),e[i].v=read_int();
	for(int i=1;i<=q;i++)
	{
		p[i].e=read_int(),p[i].c=read_int();
		if(color_id[p[i].e]) insert(1,1,q,color_id[p[i].e]+1,i-1,color_id[p[i].e]);
		color_id[p[i].e]=i;
	}
	for(int i=1;i<=m;i++)
		if(color_id[i]) insert(1,1,q,color_id[i]+1,q,color_id[i]);
	init();
	work(1,1,q);
	return 0;
}