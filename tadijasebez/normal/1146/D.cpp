#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int inf=1e9+7;
int mn[N];
bool was[N];
int main()
{
	int n,m,a,b,i;
	scanf("%i %i %i",&m,&a,&b);
	n=min(m,a+b-1);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,0});
	for(i=1;i<=n;i++) mn[i]=inf;
	while(pq.size())
	{
		int x=pq.top().second;
		int val=pq.top().first;
		pq.pop();
		if(was[x]) continue;
		//printf("%i\n",x);
		was[x]=1;
		mn[x]=max(mn[x],x);
		if(x+a<=n)
		{
			if(mn[x+a]>mn[x])
			{
				mn[x+a]=mn[x];
				pq.push({max(mn[x+a],x+a),x+a});
			}
		}
		if(x-b>0)
		{
			if(mn[x-b]>mn[x])
			{
				mn[x-b]=mn[x];
				pq.push({max(mn[x-b],x-b),x-b});
			}
		}
	}
	ll ans=0;
	//for(i=0;i<=n;i++) printf("%i ",mn[i]);printf("\n");
	for(i=0;i<=n;i++) if(mn[i]!=inf)
	{
		ans+=n-mn[i]+1;
	}
    int g=__gcd(a,b);
    int l=n+1,r=m;
    while(l<=m && l%g!=0) ans+=l/g+1,l++;
	while(r>=l && r%g!=g-1) ans+=r/g+1,r--;
	if(l>r) return 0*printf("%lld\n",ans);
	int L=l/g-1,R=r/g;
	ans+=(ll)g*(R+1)*(R+2)/2;
	ans-=(ll)g*(L+1)*(L+2)/2;
	printf("%lld\n",ans);
	return 0;
}