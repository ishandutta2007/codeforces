#include <bits/stdc++.h>
using namespace std;
int n,maxi,ans=0x3f3f3f3f;
int main()
{
	scanf("%d",&n);
	int maxi=sqrt(n);
	for(int i=1;i<=maxi;i++)
		ans=min(ans,i+(int)ceil(n/(double)i));
	printf("%d",ans);
	return 0;
}