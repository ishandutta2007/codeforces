#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m;
		k=n-m;
		int ans=n*(n+1)/2;
		m++;
		int zh=k/m,y=k-zh*m,x=m-y;
		ans-=zh*(zh+1)/2*x;
		ans-=(zh+1)*(zh+2)/2*y;
		cout<<ans<<endl;
	}
	return 0;
}