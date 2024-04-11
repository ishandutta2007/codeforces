#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
char s[200005];
int n,k;
ll f[200005],tree[1000005];
void pushup(int o)
{
	tree[o]=min(tree[lson],tree[rson]);
}
void update(int o,int l,int r,int p,ll v)
{
	if(l==r)
	{
		tree[o]=v;
		return;
	}
	if(p<=mid)update(lson,l,mid,p,v);
	else update(rson,mid+1,r,p,v);
	pushup(o);
}
ll ask(int o,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[o];
	ll ans=1e18;
	if(from<=mid)ans=min(ans,ask(lson,l,mid,from,to));
	if(to>mid)ans=min(ans,ask(rson,mid+1,r,from,to));
	return ans;
}
int main()
{
	memset(tree,0x3f,sizeof(tree));
	memset(f,0x3f,sizeof(f));
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	f[0]=0;
	update(1,0,n,0,0);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')f[i]=min(f[i],f[i-1]+i);
		else f[min(i+k,n)]=min(f[min(i+k,n)],ask(1,0,n,max(i-k-1,0),n)+i);
		update(1,0,n,min(i+k,n),f[min(i+k,n)]);
		f[i]=min(f[i],ask(1,0,n,i+1,n));
		update(1,0,n,i,f[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}