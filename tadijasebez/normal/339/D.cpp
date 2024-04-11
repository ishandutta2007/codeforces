#include <stdio.h>
#include <vector>
using namespace std;
int Matrix[1<<17][18];
int main()
{
	int n,m,i,j,x,t;
	scanf("%i %i",&n,&m);
	for(i=0;i<1<<n;i++) scanf("%i",&Matrix[i][0]);
	for(j=0;j<n;j++)
	{
		if(j%2==0)
		{
			for(i=0;i<1<<(n-j);i+=2)
			{
				Matrix[i>>1][j+1]=Matrix[i][j]|Matrix[i+1][j];
			}
		}
		else
		{
			for(i=0;i<1<<(n-j);i+=2)
			{
				Matrix[i>>1][j+1]=Matrix[i][j]^Matrix[i+1][j];
			}
		}
		//for(i=0;i<1<<(n-j);i++) printf("%i ",Matrix[i][j]);
		//printf("\n");
	}
	//printf("%i\n",Matrix[0][n]);
	while(m--)
	{
		scanf("%i%i",&t,&x);
		t--;
		Matrix[t][0]=x;
		for(j=0;j<n;j++)
		{
			if(j%2==0)
			{
				if(t%2==0)
				{
					x|=Matrix[t+1][j];
					t>>=1;	
				}
				else
				{
					x|=Matrix[t-1][j];
					t--;
					t>>=1;
				}
			}
			else
			{
				if(t%2==0)
				{
					x^=Matrix[t+1][j];
					t>>=1;
				}
				else
				{
					x^=Matrix[t-1][j];
					t--;
					t>>=1;
				}
			}
			Matrix[t][j+1]=x;
			//printf("%i %i\n",t,x);
		}
		printf("%i\n",x);
	}
	return 0;
}