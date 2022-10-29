#include <iostream>
#include <set>
#include <cstdio>
#include <map>
using namespace std;
int a[600010];
const int N=6e5+9;
struct stree
{
	int l,r,sum,lazy;
}t[N<<2];
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
		t[now].sum=a[l],t[now].lazy=0;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].sum=min(t[now*2].sum,t[now*2+1].sum);
}
inline void pushdown(int now)
{
	int lazy=t[now].lazy;
	if(lazy==0) return ;
	t[now].sum+=lazy;
	if(t[now].l!=t[now].r) t[now*2].lazy+=lazy,t[now*2+1].lazy+=lazy;
	t[now].lazy=0;
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
	if(t[now].l!=t[now].r) pushdown(now*2),pushdown(now*2+1),t[now].sum=min(t[now*2].sum,t[now*2+1].sum);
}
inline int query(int now,int l,int r)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r) return t[now].sum;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else return min(query(now*2,l,t[now*2].r),query(now*2+1,t[now*2+1].l,r));
}
multiset <int> s;
set <pair<int,int> > s2;
int main()
{
	int n,k,m;
	cin >> n >> k >> m;
	for(int i=1;i<=N;i++)
		a[i]=n-i;
	build(1,1,N);
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		if(s2.find({x,y})!=s2.end())
		{
			s2.erase({x,y});
			x=max(x,k)-min(x,k)+y;
			change(1,1,x,1);
			s.erase(s.find(x));
		}
		else
		{
			s2.insert({x,y});
			x=max(x,k)-min(x,k)+y;
			change(1,1,x,-1);
			s.insert(x);
		}
		if(s.empty()) puts("0");
		else
			cout << max(1,-query(1,1,*(--s.end())))-1 << "\n";
	}
	return 0;
}