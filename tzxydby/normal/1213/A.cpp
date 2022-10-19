#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a=0,b=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x&1) a++;
		else b++;
	}
	printf("%d\n",min(a,b));
	return 0;
}