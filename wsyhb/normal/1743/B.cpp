#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d ",1,n);
		for(int i=2;i<=n-1;++i)
			printf("%d%c",i," \n"[i==n-1]);
	}
	return 0;
}