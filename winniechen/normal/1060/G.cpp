#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 100005;
typedef long long ll;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s;
int n,Q,a[N],cnt;ll ans[N];
struct QaQ
{
	ll x;int p,idx;
	inline bool operator < (const QaQ &a) const {return x<a.x;}
}q[N],f[N];
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=Q;i++)
	{
		cnt++;scanf("%lld%d",&q[cnt].x,&q[cnt].p);
		if(q[cnt].x<a[1])ans[i]=q[cnt].x,cnt--;else q[cnt].idx=i;
	}sort(q+1,q+1+cnt);
	for(int i=0;i<n;i++)s.insert(i);
	ll now=1e18,tim=0;int i=n,j=cnt;
	while(j)
	{
		ll x=(now-a[i]-1)/i+1;
		while(j&&q[j].x>=now-i*x)
			f[j]=(QaQ){tim+(now-q[j].x-1)/i+1-q[j].p,*s.find_by_order(i-(now-q[j].x+i-1)%i-1),q[j].idx},j--;
		tim+=x,now-=i*x;
		while(i&&a[i]>=now)s.erase(s.find_by_order(a[i--]-now));
	}
	s.clear();sort(f+1,f+cnt+1);
	for(int i=0;i<n;i++)s.insert(i);
	now=1e18,tim=0;i=n,j=1;
	while(j<=cnt)
	{
		ll x=(now-a[i]-1)/i+1;
		while(j<=cnt&&tim+x>=f[j].x)
			ans[f[j].idx]=now+s.order_of_key(f[j].p)-(f[j].x-tim)*i,j++;
		tim+=x,now-=i*x;
		while(i&&a[i]>=now)s.erase(s.find_by_order(a[i--]-now));
	}
	for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
}