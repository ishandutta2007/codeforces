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
const int max_n=2e5+5;
int a[max_n];
long long sum[max_n];
struct node
{
	long long val;
	int id;
}q[max_n];
struct node1
{
	int l,r;
}b[max_n<<2];
bool cmp_node(node x,node y)
{
	return x.val!=y.val?x.val<y.val:x.id<y.id;
}
bool cmp_node1(node1 x,node1 y)
{
	return x.r=y.r?x.r<y.r:x.l<y.l; 
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
		q[i].val=sum[i];
		q[i].id=i;
	}
	sort(q,q+n+1,cmp_node);
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(q[i].val==q[i-1].val)
		{
			b[++cnt].l=q[i-1].id+1;
			b[cnt].r=q[i].id-1;
		}
	sort(b+1,b+cnt+1,cmp_node1);
	int now=0;
	int ans=0;
	for(int i=1;i<=cnt;++i)
	{
		if(now>=b[i].l)
			continue;
		++ans;
		now=b[i].r;
	}
	printf("%d",ans);
	return 0;
}