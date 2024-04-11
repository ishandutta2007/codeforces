#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
struct Point
{
	int x,y;
	inline Point(int a=0,int b=0) {x=a,y=b;}
};
inline bool cmp(const Point &a,const Point &b)
{
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
inline Point operator - (const Point &a,const Point &b)
{
	return Point(a.x-b.x,a.y-b.y);
}
inline long long cp(const Point &a,const Point &b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
vector<Point> p[max_n<<2];
void Insert(int k,int l,int r,int a,int b,const Point &v)
{
	if(a<=l&&r<=b)
	{
		p[k].push_back(v);
		return;
	}
	int mid=(l+r)>>1;
	if(a<=mid)
		Insert(k<<1,l,mid,a,b,v);
	if(b>mid)
		Insert(k<<1|1,mid+1,r,a,b,v);
}
int st[max_n],tp;
void update(int k,int l,int r)
{
	sort(p[k].begin(),p[k].end(),cmp);
	tp=0;
	for(int i=0;i<int(p[k].size());++i)
	{
		while(tp>=2&&cp(p[k][st[tp]]-p[k][st[tp-1]],p[k][i]-p[k][st[tp-1]])>=0)
			--tp;
		st[++tp]=i;
	}
	for(int i=0;i<tp;++i)
		p[k][i]=p[k][st[i+1]];
	p[k].resize(tp);
	if(l<r)
	{
		int mid=(l+r)>>1;
		update(k<<1,l,mid);
		update(k<<1|1,mid+1,r);
	}
}
const long long inf=4e18;
long long ans;
void query(int k,int l,int r,int x,int q)
{
	if(p[k].size())
	{
		int l=0,r=int(p[k].size())-2,res=int(p[k].size())-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(1ll*p[k][mid].x*q+p[k][mid].y<=1ll*p[k][mid+1].x*q+p[k][mid+1].y)
				l=mid+1;
			else
				res=mid,r=mid-1;
		}
		ans=max(ans,1ll*p[k][res].x*q+p[k][res].y);
	}
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(x<=mid)
			query(k<<1,l,mid,x,q);
		else
			query(k<<1|1,mid+1,r,x,q);
	}
}
int t[max_n],a[max_n],b[max_n],q[max_n];
bool del[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",t+i);
		if(t[i]==1)
			scanf("%d%d",a+i,b+i);
		else if(t[i]==2)
		{
			int id;
			scanf("%d",&id);
			Insert(1,1,n,id,i-1,Point(a[id],b[id]));
			del[id]=true;
		}
		else
			scanf("%d",q+i);
	}
	for(int i=1;i<=n;++i)
	{
		if(t[i]==1&&!del[i])
			Insert(1,1,n,i,n,Point(a[i],b[i]));
	}
	update(1,1,n);
	for(int i=1;i<=n;++i)
	{
		if(t[i]==3)
		{
			ans=-inf;
			query(1,1,n,i,q[i]);
			if(ans==-inf)
				puts("EMPTY SET");
			else
				printf("%lld\n",ans);
		}
	}
	return 0;
}