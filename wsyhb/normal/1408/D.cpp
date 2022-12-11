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
const int max_n=2e3+5;
const int max_m=2e3+5;
int a[max_n],b[max_n],c[max_m],d[max_m];
const int max_t=4e6+5;
struct node
{
	int x,y;
}q[max_t];
bool operator < (const node &a,const node &b)
{
	return a.x>b.x;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%d",a+i,b+i);
	for(int i=1;i<=m;++i)
		scanf("%d%d",c+i,d+i);
	int t=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i]<=c[j]&&b[i]<=d[j])
			{
				q[++t].x=c[j]-a[i]+1;
				q[t].y=d[j]-b[i]+1;
			}
	sort(q+1,q+t+1);
	int ans=1e9;
	int max_y=0;
	for(int i=1;i<=t+1;++i)
	{
		ans=min(ans,q[i].x+max_y);
		max_y=max(max_y,q[i].y);
	}
	printf("%d",ans);
	return 0;
}