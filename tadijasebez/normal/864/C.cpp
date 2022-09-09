#include <stdio.h>
int Fuel,sol,dist1,dist2;
int main()
{
	int a,b,f,k,i;
	scanf("%i %i %i %i",&a,&b,&f,&k);
	dist1=f*2;
	dist2=(a-f)*2;
	Fuel=b-f;
	if(Fuel<0)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<k;i++)
	{
		if(i&1)
		{
			if(dist2>Fuel) Fuel=b,sol++;
			Fuel-=dist2;
		}
		else
		{
			if(dist1>Fuel) Fuel=b,sol++;
			Fuel-=dist1;
		}
		if(Fuel<0)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(k&1)
	{
		if(Fuel<(a-f)) Fuel=b,sol++;
		Fuel-=(a-f);
	}
	else
	{
		if(Fuel<f) Fuel=b,sol++;
		Fuel-=f;
	}
	if(Fuel<0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%i\n",sol);
	return 0;
}