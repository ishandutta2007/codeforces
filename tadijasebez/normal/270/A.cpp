#include <stdio.h>
#include <cmath>
int main()
{
	int q,i,a,b,c;
	double angle;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&a);
		i=3;
		bool ok=false;
		do
		{
			angle=180.00-(360.00/i);
			b=floor(angle);
			c=ceil(angle);
			if(a==b && a==c) printf("YES\n"),ok=true;
			i++;
		} while(b<a);
		if(!ok) printf("NO\n");
	}
	return 0;
}