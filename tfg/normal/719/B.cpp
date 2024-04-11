#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

std::string str;


int main()
{
	int n;
	int b[2], r[2];//0=comeca em b, 1=comeca em r
	b[0]=b[1]=r[0]=r[1]=0;
	scanf("%i", &n);
	std::cin >> str;
	for(int i=0;i<n;i++)
	{
		if(i&1)
		{
			if(str[i]=='b')
				b[0]++;
			else
				r[1]++;
		}
		else
		{
			if(str[i]=='r')
				r[0]++;
			else
				b[1]++;
		}
	}
	int ans1=std::max(b[0],r[0]);
	int ans2=std::max(b[1],r[1]);
	printf("%i",std::min(ans1,ans2));
}