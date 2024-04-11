#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
struct node
{
	int x,y;
}a[800005];
inline bool cmp(node x,node y)
{
	return x.y<y.y;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,t,A,B;
		scanf("%lld%lld%lld%lld",&n,&t,&A,&B);
		int cntx=0,cnty=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i].x);
		for(int i=1;i<=n;i++) if(a[i].x) a[i].x=B,++cnty;else a[i].x=A,++cntx;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i].y);
		sort(a+1,a+n+1,cmp);
		int ans=0,_=0;
		int X=0;
		if(cntx*A>=a[1].y-1)
			ans=max(ans,(a[1].y-1)/A);
		else
			ans=max(cntx+min((a[1].y-1-A*cntx)/B,cnty),ans);
		a[n+1].y=t+1;
		for(int i=1;i<=n;i++)
		{
			_+=a[i].x;
			if(a[i].x==B) --cnty;
			else --cntx;
			if(_<a[i+1].y)
			{
				if(cntx*A>=a[i+1].y-_-1)
				{
					ans=max(ans,i+(a[i+1].y-_-1)/A);
					//cout << i+(a[i+1].y-_)/A << "*";
				}
				else
				{
					ans=max(i+cntx+min((a[i+1].y-_-1-A*cntx)/B,cnty),ans);
					//cout << i+cntx+min((a[i+1].y-_-A*cntx)/B,cnty) << "!";
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}