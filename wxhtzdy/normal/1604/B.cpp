#include <bits/stdc++.h>
using namespace std;

int T,n,A[5000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",A+i);
		}
		if(!(n&1))
		{
			printf("YES\n");
		}
		else
		{
			int kk=0;
			for(int i=1;i<=n-1;i++)
			{
				if(A[i]>=A[i+1])
				{
					kk=1;
				}
			}
			if(kk)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}