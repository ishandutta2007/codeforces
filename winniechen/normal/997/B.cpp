#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,i,j,ans;
main()
{
	scanf("%lld",&n);
	for(i=0;i<=min(n,8ll);i++)
	for(j=0;j<=min(n-i,8ll);j++)
	if(i==0||j<5)ans+=n-i-j+1;
	cout<<ans;
	return 0;
}