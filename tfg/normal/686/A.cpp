#include <cstdio>
#include <string>
#include <iostream>

long long int n, x;

int main()
{
	scanf("%lli %lli",&n,&x);
	std::string str;
	int d;
	int distress=0;
	for(int i=0;i<n;i++)
	{
		std::cin>>str>>d;
		if(str[0]=='+')
			x+=d;
		else
		{
			if(d>x)
				distress++;
			else
				x-=d;
		}
	}
	printf("%lli %i\n",x,distress);
}