#include <bits/stdc++.h>
using namespace std;
int n,k; 
int main()
{
	scanf("%d%d",&n,&k);
	int a=(n-k)/2;
	for(int i=1;i<=n;i++)
	{
		if(i%(a+1)) printf("1");
		else printf("0");
	}
	return 0;
}