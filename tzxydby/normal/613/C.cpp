#include<bits/stdc++.h>
using namespace std;
int n,a[30],g,s,t;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2)
			s++,t=i;
		g=__gcd(g,a[i]);
	}
	if(s==0)
	{
		printf("%d\n",g);
		for(int i=1;i<=g/2;i++)
		{
			for(int j=0;j<=25;j++)
				for(int k=1;k<=a[j]/g;k++)
					printf("%c",'a'+j);
			for(int j=25;j>=0;j--)
				for(int k=1;k<=a[j]/g;k++)
					printf("%c",'a'+j);
		}
	}
	else if(s==1)
	{
		printf("%d\n",g);
		for(int i=1;i<=g;i++)
		{
			for(int j=0;j<=25;j++)
				for(int k=1;k<=a[j]/g/2;k++)
					if(j!=t)
						printf("%c",'a'+j);
			for(int k=1;k<=a[t]/g;k++)
				printf("%c",'a'+t);
			for(int j=25;j>=0;j--)
				for(int k=1;k<=a[j]/g/2;k++)
					if(j!=t)
						printf("%c",'a'+j);
		}
	}
	else
	{
		printf("%d\n",0);
		for(int i=0;i<=25;i++)
			for(int j=1;j<=a[i];j++)
				printf("%c",'a'+i);
	}
	return 0;
}