#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,ans1=0,ans2=0,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x%2==0)ans1++;
		else ans2++;
	}
	printf("%d\n",min(ans1,ans2));
	return 0;
}