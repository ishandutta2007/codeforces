#include<stdio.h>
typedef unsigned u;
u u25,u50,u100,t,n;
int main()
{
	for(scanf("%u",&t);t--;)
	{
		scanf("%u",&n);
		if(n==25)u25++;
		else if(n==50)
		{
			if(!u25){printf("NO\n");return 0;}
			u50++;u25--;
		}
		else
		{
			if(u50&&u25)
			{
				u100++;u50--;u25--;
			}
			else if(u25>2)
			{
				u100++;u25-=3;
			}
			else{printf("NO\n");return 0;}
		}
	}
	printf("YES\n");
	return 0;
}