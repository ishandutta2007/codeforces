//+ 
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
const int N=1e5+5;
struct Node
{
	int x,r,f;
}node[N];
bool cmp(Node p,Node q)
{
	return p.r>q.r;
}
const int M=17e6+5;
int ls[M],rs[M],val[M];
int tot; 
void modify(int k,int a,int b,int x,int s)
{
	val[k]+=s;
	if(a==b) return;
	int mid=(a+b)>>1;
	if(x<=mid)
	{
		if(!ls[k]) ls[k]=++tot;
		modify(ls[k],a,mid,x,s); 
	}
	else
	{
		if(!rs[k]) rs[k]=++tot;
		modify(rs[k],mid+1,b,x,s);
	}
}
typedef long long ll;
ll ans; 
void query(int k,int a,int b,int l,int r)
{
	if(l<=a&&b<=r)
	{
		ans+=val[k];
		return; 
	}
	int mid=(a+b)>>1;
	if(l<=mid&&ls[k]) query(ls[k],a,mid,l,r);
	if(r>mid&&rs[k]) query(rs[k],mid+1,b,l,r);
}
int main()
{
	int n=read_int(),k=read_int();
	for(int i=1;i<=n;i++) node[i].x=read_int(),node[i].r=read_int(),node[i].f=read_int();
	sort(node+1,node+n+1,cmp);
	int F=1e4;
	tot=F;
	int X=1e9;
	for(int i=1;i<=n;i++)
	{
		int lf=max(1,node[i].f-k);
		int rf=min(F,node[i].f+k);
		for(int j=lf;j<=rf;j++) query(j,1,X,node[i].x-node[i].r,node[i].x+node[i].r);
		modify(node[i].f,1,X,node[i].x,1);
	}
	printf("%lld",ans);
	return 0;
}