#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
#define maxn 300005
int n,k;
struct data
{
	ll t,b;
}a[maxn];
bool operator < (data A,data B)
{
	return A.b>B.b;
}
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%I64d%I64d",&a[i].t,&a[i].b);
	sort(a+1,a+n+1);
	int sz=0;
	ll sum=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		if(sz<k)
		{
			sz++;
			pq.push(a[i].t);sum+=a[i].t;
			ans=max(ans,sum*a[i].b);
		}
		else
		{
			sum+=a[i].t; pq.push(a[i].t);
			ll x=pq.top();pq.pop();
			sum-=x;
			ans=max(ans,sum*a[i].b);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}