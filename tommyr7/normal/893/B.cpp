#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
bool check(int x)
{
	int now=1;
	for (int i=1;;i++)
	{
		if (now*(now*2-1)==x) return true;
		if (now*(now*2-1)>x) return false;
		now*=2;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		if (check(i)&&(n%i==0)) ans=i;
	printf("%d\n",ans);
	return 0;
}