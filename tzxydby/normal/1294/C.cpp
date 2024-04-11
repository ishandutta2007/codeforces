#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=0;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i)
				continue;
			int m=n/i;
			for(int j=i+1;j*j<m;j++)
			{
				if(m%j)
					continue;
				printf("YES\n%d %d %d\n",i,j,m/j);
				flag=1;
				break;
			}
			if(flag)
				break;
		}
		if(!flag)
			puts("NO");
	}
	return 0;
}