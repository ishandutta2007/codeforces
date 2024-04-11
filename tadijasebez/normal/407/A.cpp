#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int a,b,i,j,k;
	scanf("%i %i",&a,&b);
	if(a>b) swap(a,b);
	for(i=1;i<a;i++)
	{
		for(j=1;j<a;j++)
		{
			if((ll)i*i+(ll)j*j==(ll)a*a)
			{
				int iz=i/__gcd(i,j),jz=j/__gcd(i,j);
				for(k=1;k*iz<b && k*jz<b;k++)
				{
					if((ll)iz*k*iz*k+(ll)jz*k*jz*k==(ll)b*b && iz*k!=j)
					{
						printf("YES\n");
						printf("%i %i\n",0,0);
						printf("%i %i\n",i,j);
						printf("%i %i\n",-k*jz,iz*k);
						return 0;
					}
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}