#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n;
typedef long long ll;
ll A,cf,cm,m,qzh[233333],anss[233333];
pair<ll,int> as[233333];
ll sum(ll l,ll r) {return qzh[r]-qzh[l-1];}
int main()
{
	cin>>n>>A>>cf>>cm>>m;
	for(int i=1;i<=n;i++) cin>>as[i].first,as[i].second=i;
	sort(as+1,as+1+n);
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+as[i].first;
	m+=A; ll ans=0LL,L,R;
	for(int i=n+1;i>=1;i--)
	{
		m-=A-as[i].first;
		if(m<0) continue;
		ll l=0,r=A;
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			int ps=lower_bound(as+1,as+1+n,make_pair(mid,0))-as-1;
			ps=min(ps,i-1);
			if(ps*mid-qzh[ps]<=m) l=mid;
			else r=mid-1;
		}
		if((n+1-i)*cf+l*cm>ans)
		{
			ans=(n+1-i)*cf+l*cm;
			L=l; R=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i>=R) anss[as[i].second]=A;
		else if(as[i].first<=L) anss[as[i].second]=L;
		else anss[as[i].second]=as[i].first;
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;i++) printf("%I64d ",anss[i]);
}