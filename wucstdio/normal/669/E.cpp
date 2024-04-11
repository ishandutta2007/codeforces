#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
struct Query
{
	int opt;
	int t,x,p;
}q[100005],tmp[100005];
int n,ans[100005],top;
map<int,int>mp;
bool cmp(Query a,Query b)
{
	return a.t<b.t||a.t==b.t&&a.opt<b.opt;
}
void work(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	work(l,mid);
	mp.clear();
	top=0;
	for(int i=l;i<=mid;i++)
	  if(q[i].opt==1||q[i].opt==2)
		tmp[++top]=q[i];
	for(int i=mid+1;i<=r;i++)
	  if(q[i].opt==3)
	    tmp[++top]=q[i];
	sort(tmp+1,tmp+top+1,cmp);
	for(int i=1;i<=top;i++)
	{
		if(tmp[i].opt==1)mp[tmp[i].x]++;
		if(tmp[i].opt==2)mp[tmp[i].x]--;
		if(tmp[i].opt==3)ans[tmp[i].p]+=mp[tmp[i].x];
	}
	work(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&q[i].opt,&q[i].t,&q[i].x);
		q[i].p=i;
	}
	work(1,n);
	for(int i=1;i<=n;i++)
	  if(q[i].opt==3)
	    printf("%d\n",ans[i]);
	return 0;
}