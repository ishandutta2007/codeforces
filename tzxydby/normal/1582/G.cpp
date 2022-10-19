#include<bits/stdc++.h>
using namespace std;
const int N=1000005,mx=1000001;
int n,a[N],pr[N],tr[N<<2],v[N],st[N],tp;
char b[N];
vector<int>fc[N],p[N];
long long ans;
inline int cal(int v,int x){int c=0;while(v%x==0)v/=x,c++;return c;}
void build(int k,int l,int r)
{
	tr[k]=mx;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(a>b)
		return;
	if(l==a&&r==b)
	{
		tr[k]=min(tr[k],v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
}
int ask(int k,int l,int r,int x)
{
	int v=tr[k];
	if(l==r)
		return v;
	int mid=l+r>>1;
	if(x<=mid) v=min(v,ask(k<<1,l,mid,x));
	else v=min(v,ask(k<<1|1,mid+1,r,x));
	return v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",b+1);
	for(int i=2;i<=mx;i++)
		for(int j=i+i;j<=mx;j+=i)
			pr[j]=1;
	for(int i=2;i<=mx;i++)
		if(!pr[i])
			for(int j=i;j<=mx;j+=i)
				fc[j].push_back(i);
	for(int i=1;i<=n;i++)
		for(auto j:fc[a[i]])
			p[j].push_back(i);
	build(1,1,n);
	for(int i=2;i<=mx;i++)
	{
		if(pr[i])
			continue;
		int m=p[i].size();
		if(!m)
			continue;
		for(int j=0;j<m;j++)
			v[j]=(j?v[j-1]:0)+cal(a[p[i][j]],i)*(b[p[i][j]]=='*'?1:-1);
		tp=0;
		st[++tp]=m-1;
		for(int j=m-1;j>=0;j--)
		{
			while(tp&&v[st[tp]]>=(j?v[j-1]:0))
				tp--;
			if(tp)
				upd(1,1,n,j?p[i][j-1]+1:1,p[i][j],p[i][st[tp]]);
			st[++tp]=j-1;
		}
	}
	for(int i=1;i<=n;i++)
		ans+=min(n+1,ask(1,1,n,i))-i;
	printf("%lld\n",ans);
	return 0;
}