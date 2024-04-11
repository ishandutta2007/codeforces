#include <stdio.h>
int main()
{
	int q;
	int n,k,d;
	scanf("%d %d",&n,&q);
	int t,ot[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		ot[i]=0;
	}

	for (int i = 0; i < q; ++i)
	{	

		int sum = 0;
		scanf("%d %d %d",&t,&k,&d);
		int temp = k;
		for (int i = 1; i <= n; ++i)
		{
			if(t<ot[i]) continue;

			k=k-1;
			if (k==0)
			{
				break;
			}


		}
		if (k==0)
		{
			k= temp;
		for (int i = 1; i <= n; ++i)
		{
			if(t<ot[i]) continue;
			sum = sum + i;
			ot[i] = t + d;
			k=k-1;
			if (k==0)
			{
				break;
			}


		}
			 printf("%d\n",sum );
		}
		else{
			printf("-1\n");
		}
	}
	
	return 0;
}