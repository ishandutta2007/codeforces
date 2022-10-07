#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid ((l+r)>>1)
using namespace std;
int n,m,sum[2400005],pos[300005],ans[300005];
void pushup(int o)
{
	sum[o]=sum[lson]+sum[rson];
}
void update(int o,int l,int r,int p)
{
	if(l==r)
	{
		sum[o]^=1;
		return;
	}
	if(p<=mid)update(lson,l,mid,p);
	else update(rson,mid+1,r,p);
	pushup(o);
}
int ask(int o,int l,int r,int from,int to)
{
	if(from>to)return 0;
	if(l>=from&&r<=to)return sum[o];
	int ans=0;
	if(from<=mid)ans+=ask(lson,l,mid,from,to);
	if(to>mid)ans+=ask(rson,mid+1,r,from,to);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)pos[i]=i,update(1,0,n+m,i+m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		ans[x]=max(ans[x],ask(1,0,n+m,0,pos[x]-1+m)+1);
		update(1,0,n+m,pos[x]+m);
		pos[x]=-i;
		update(1,0,n+m,pos[x]+m);
	}
	for(int i=1;i<=n;i++)ans[i]=max(ans[i],ask(1,0,n+m,0,pos[i]-1+m)+1);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",pos[i]>0?i:1);
		printf("%d\n",ans[i]);
	}
	return 0;
}