#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]=abs(a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid,aa=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[mid]*2<a[i])
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
				aa=mid;
			}
		}
//		printf("%I64d %I64d\n",i,ans);
		ans+=(i-aa);
	}
	cout<<ans<<endl;
	return 0;
}