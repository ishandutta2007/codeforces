#include <bits/stdc++.h>
using namespace std;
int ans,y[55],n,x[55];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		ans+=x[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&y[i]);
		ans-=y[i];
	}
	if(ans>=0)
		printf("Yes");
	else
		printf("No");
	return 0;
}