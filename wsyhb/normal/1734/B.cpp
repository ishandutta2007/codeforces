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
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=i;++j)
				printf("%d%c",j==1||j==i," \n"[j==i]);
		}
	}
	return 0;
}