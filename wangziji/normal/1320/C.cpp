#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma GCC optimize 2
using namespace std;
const int N=1e6+9;
struct stree
{
	int l,r,lazy,sum;
}t[N<<2];
int s[N];
inline void pushdown(int now)
{
	int lazy=t[now].lazy;if(!lazy) return ;
	if(t[now].l!=t[now].r) t[now*2].lazy+=lazy,t[now*2+1].lazy+=lazy;
	t[now].sum+=lazy;t[now].lazy=0;
}
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
		t[now].sum=s[l],t[now].lazy=0;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].sum=max(t[now*2].sum,t[now*2+1].sum);
}
inline void change(int now,int l,int r,int d)
{
	if(t[now].l==l&&t[now].r==r)
	{
		t[now].lazy+=d;
		return ;
	}
	pushdown(now);
	if(t[now*2].r>=r) change(now*2,l,r,d);
	else if(t[now*2+1].l<=l) change(now*2+1,l,r,d);
	else change(now*2,l,t[now*2].r,d),change(now*2+1,t[now*2+1].l,r,d);
	pushdown(now);
	if(t[now].l!=t[now].r) pushdown(now*2),pushdown(now*2+1),t[now].sum=max(t[now*2].sum,t[now*2+1].sum);
}
inline int query(int now,int l,int r)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r) return t[now].sum;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else return max(query(now*2,l,t[now*2].r),query(now*2+1,t[now*2+1].l,r));
}
pair <int,int> a[200005];
pair <int,int> b[200005];
pair <pair<int,int>,int> c[200005];
int ans=-2e9;
signed main() {
	int n,m,p;
	cin >> n >> m >> p;
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=1;i<=m;i++) scanf("%d%d",&b[i].first,&b[i].second);
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&c[i].first.first,&c[i].first.second,&c[i].second);
		++c[i].first.first,++c[i].first.second;
	}
	sort(a+1,a+n+1),sort(b+1,b+m+1),sort(c+1,c+p+1);
	for(int i=1;i<=1000000;i++) s[i]=-2e9;
	for(int i=1;i<=m;i++) s[b[i].first]=max(s[b[i].first],-b[i].second);
	build(1, 1, 1000000);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		while(now<=p&&a[i].first>=c[now].first.first)
		{
			if(c[now].first.second<=1000000)
			{
				change(1,c[now].first.second,1000000,c[now].second);
//				cout << c[now].first.second << " " << 1000000 << " " << c[now].second << "\n";
			}
			++now;
		}
//		cout << query(1,1,1000000) << "\n";
		ans=max(ans,query(1,1,1000000)-a[i].second);
//		cout << ans << "\n";
	}
	cout << ans;
	return 0;
}