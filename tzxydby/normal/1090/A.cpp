#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int a[N],s[N]; 
main()
{
	int n,m,x,maxt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int maxx=0;
		for(int j=1;j<=s[i];j++)
		{
			cin>>x;
			maxx=max(maxx,x); 
		}
		a[i]=maxx;
		maxt=max(maxt,maxx); 
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=(maxt-a[i])*s[i];
	cout<<ans<<endl;
	return 0;
}