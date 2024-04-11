#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n>(long long)k*(k-1))
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	int tmp=n;
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
		{
			printf("%d %d\n",i,j);
			if(tmp==1) return 0;
			printf("%d %d\n",j,i);
			if(tmp==2) return 0;
			tmp-=2;
		}
	return 0;
}