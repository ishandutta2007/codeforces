#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
inline char read_char()
{
    if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    bool flag=false;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_m=1e5+5;
const int max_n=1e5+5;
int a[max_m],b[max_n];
const int Cnt_v=2e5+5;
int f[Cnt_v];
int get_fa(int x)
{
	return f[x]!=x?f[x]=get_fa(f[x]):x;
}
inline bool merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		f[x]=y;
		return true;
	}
	return false;
}
const int Cnt_e=2e5+5;
struct edge
{
	int x,y,z;
	inline edge(int a=0,int b=0,int c=0)
	{
		x=a,y=b,z=c;
	}
}e[Cnt_e];
inline bool cmp(const edge &a,const edge &b)
{
	return a.z>b.z;
}
int main()
{
	int m=read_int(),n=read_int();
	for(int i=1;i<=m;++i)
		a[i]=read_int();
	for(int i=1;i<=n;++i)
		b[i]=read_int();
	long long ans=0;
	int cnt_e=0;
	for(int i=1;i<=m;++i)
	{
		int s=read_int();
		for(int j=1;j<=s;++j)
		{
			int x=read_int();
			ans+=a[i]+b[x];
			e[++cnt_e]=edge(i,x+m,a[i]+b[x]);
		}
	}
	sort(e+1,e+cnt_e+1,cmp);
	for(int i=1;i<=m+n;++i)
		f[i]=i;
	for(int i=1;i<=cnt_e;++i)
		if(merge(e[i].x,e[i].y))
			ans-=e[i].z;
	printf("%lld",ans);
	return 0;
}