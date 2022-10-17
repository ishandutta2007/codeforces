#include<stdio.h>
int n,m,k;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	if(n&1)
		for(int i=1;i*i<=m;i++)
			if(m%i==0)
				if(m/i>1&&i>=k||i>1&&m/i>=k)
					return puts("Timur");
	puts("Marsel");
}