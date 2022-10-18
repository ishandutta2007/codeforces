#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,a;
	cin>>n>>l>>a;
	int u,v;
	int la=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&u,&v);
		ans+=(u-la)/a;
		la=u+v;
	}
	ans+=(l-la)/a;
	cout<<ans<<endl;
	return 0;
}