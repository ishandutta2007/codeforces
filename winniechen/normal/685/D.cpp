#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define N 100005
#define ll long long
struct node
{
	int x,y;
	friend bool operator<(const node &a,const node &b)
	{
		return a.x<b.x;
	}
}a[N];
struct nod
{
	int l,r,y,type,rl,rr;
	friend bool operator<(const nod &a,const nod &b)
	{
		return a.y<b.y;
	}
}q[N<<1];
vector<int > v;
int k,n;ll ans[N];
int main()
{
	scanf("%d%d",&n,&k);
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int st;
		if(v.empty())st=a[i].x-k+1;
		else st=max(v.back()+1,a[i].x-k+1);
		for(int j=st;j<=a[i].x;j++)v.push_back(j);
	}
	for(int i=1;i<=n;i++)
	{
		q[++tot].rl=a[i].x-k+1;q[tot].rr=a[i].x;q[tot].y=a[i].y-k+1;q[tot].type=1;
		q[++tot].rl=a[i].x-k+1;q[tot].rr=a[i].x;q[tot].y=a[i].y+1;q[tot].type=-1;
	}
	for(int i=1;i<=tot;i++)
	{
		q[i].l=lower_bound(v.begin(),v.end(),q[i].rl)-v.begin();
		q[i].r=upper_bound(v.begin(),v.end(),q[i].rr)-v.begin();
	}
	cnt=v.size();v.clear();
    v.shrink_to_fit();sort(q+1,q+tot+1);
	vector<int>sum(cnt,0);vector<int>lst(cnt,1<<30);
	for(int i=1;i<=tot;i++)
	{
		int l=q[i].l,r=q[i].r;
		for(int j=l;j<r;j++)
		{
			if(lst[j]!=(1<<30))
			{
				ans[sum[j]]+=q[i].y-lst[j];
			}
			sum[j]+=q[i].type;
			lst[j]=q[i].y;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);puts("");return 0;
}