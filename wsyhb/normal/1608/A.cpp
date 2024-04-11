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
		for(int i=2;i<=n+1;++i)
			printf("%d%c",i,i<=n?' ':'\n');
	}
	return 0;
}