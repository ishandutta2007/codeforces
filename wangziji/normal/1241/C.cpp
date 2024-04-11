#include <iostream>
#include <algorithm>
using namespace std;
long long p[200005],a,b,c,d,X,n;
inline bool cmp(int x,int y)
{
	return x>y;
}
inline bool pd(int t)
{
	int x,y,z;
	x=y=z=0;
	for(int i=1;i<=t;i++)
	{
		if(i%a==0&&i%c==0)
			++x;
		if(i%a==0&&i%c!=0)
			++y;
		if(i%a!=0&&i%c==0)
			++z;
	}
	long long ans=0;
	for(int i=1;i<=x&&i<=n;i++)
		ans+=p[i]*(b+d);
	for(int i=x+1;i<=x+y&&i<=n;i++)
		ans+=p[i]*b;
	for(int i=x+y+1;i<=x+y+z&&i<=n;i++)
		ans+=p[i]*d;
	return ans>=X;
}
signed main() {
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> p[i];
			p[i]/=100;
		}
		sort(p+1,p+n+1,cmp);
		int l=0,r=n,ans=10000000;
		cin >> a >> b >> c >> d >> X;
		swap(a,b),swap(c,d);
		if(b<d) swap(a,c),swap(b,d);
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(pd(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		if(ans>n)
			cout << -1 << endl;
		else
			cout << ans << endl;
	 } 
	return 0;
}