#include<bits/stdc++.h>
using namespace std;
int n,q;
const int max_n=1e5+5;
int a[max_n],b[max_n],c[max_n],Log[max_n],g[19][max_n];
struct ST
{
	int type;
	inline int calc(int x,int y)
	{
		return type?max(x,y):min(x,y);
	}
	int f[17][max_n];
	inline void init(int *a)
	{
		for(int i=1;i<=n;++i)
			f[0][i]=a[i];
		for(int i=1;i<=Log[n];++i)
			for(int j=1;j+(1<<i)-1<=n;++j)
				f[i][j]=calc(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return calc(f[k][l],f[k][r-(1<<k)+1]);
	}
}mn[19],mx[19];
typedef pair<int,int> P;
inline P f(int k,P p)
{
	for(int i=0;i<19&&k>0;++i)
	{
		if(k&(1<<i))
		{
			k^=1<<i;
			int L=p.first;
			int R=p.second;
			if(L<R)
			{
				p.first=mn[i].query(L,R-1);
				p.second=mx[i].query(L,R-1);
			}
			else
				p.first=p.second=g[i][L];
		}
	}
	return p;
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%d%d",&n,&q);
	bool f1=false,f2=false;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		f1|=a[i]==1;
		f2|=a[i]==n;
	}
	if(!f1||!f2)
	{
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			puts(l==1&&r==n?"0":"-1");
		}
		return 0;
	}
	Log[0]=-1;
	for(int i=1;i<=n;++i)
		Log[i]=Log[i>>1]+1;
	int R=Log[n]+2;
	for(int i=0;i<=R;++i)
		mx[i].type=1;
	for(int i=1;i<=n-1;++i)
		b[i]=min(a[i],a[i+1]);
	mn[0].init(b);
	for(int i=1;i<=n-1;++i)
		b[i]=max(a[i],a[i+1]);
	mx[0].init(b);
	for(int i=1;i<=n;++i)
		g[0][i]=a[i]; 
	for(int k=1;k<=R;++k)
	{
		for(int i=1;i<=n;++i)
			g[k][i]=g[k-1][g[k-1][i]];
		for(int i=1;i<=n-1;++i)
		{
			int L=mn[k-1].query(i,i);
			int R=mx[k-1].query(i,i);
			if(L<R)
			{
				b[i]=mn[k-1].query(L,R-1);
				c[i]=mx[k-1].query(L,R-1);
			}
			else
				b[i]=c[i]=g[k-1][L];
		}
		mn[k].init(b),mx[k].init(c);
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(f(n<<2,P(l,r))!=P(1,n))
		{
			puts("-1");
			continue;
		}
		int L=0,R=(n<<2)-1,res=n<<2;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(f(mid,P(l,r))==P(1,n))
				res=mid,R=mid-1;
			else
				L=mid+1;
		}
		printf("%d\n",res);
	}
	return 0;
}