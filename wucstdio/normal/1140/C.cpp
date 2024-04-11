#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
struct Song
{
	int b;
	int t;
}a[300005];
priority_queue<ll,vector<ll>,greater<ll> >q;
int n,k;
ll sum,ans;
bool cmp(Song a,Song b)
{
	return a.b>b.b;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].t,&a[i].b);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		q.push(a[i].t);
		sum+=a[i].t;
		while(q.size()>k)
		{
			sum-=q.top();
			q.pop();
		}
		ans=max(ans,sum*a[i].b);
	}
	printf("%I64d\n",ans);
	return 0;
}