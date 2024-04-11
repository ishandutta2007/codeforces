#include <bits/stdc++.h>
using namespace std;
int ans,a,b;
int main()
{
	scanf("%d%d",&a,&b);
	int mid=(a+b)/2;
	for(int i=1;i<=abs(a-mid);i++)
		ans+=i;
	for(int i=1;i<=abs(b-mid);i++)
		ans+=i;
	printf("%d",ans);
	return 0;
}