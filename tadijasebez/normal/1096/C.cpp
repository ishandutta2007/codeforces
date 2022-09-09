#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,q,ang,x;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&ang);
		int b=180;
		int g=__gcd(b,ang);
		for(x=1;1;x++)
		{
			if(x*ang/g>x*b/g-2) continue;
			break;
		}
		printf("%i\n",x*b/g);
	}
	return 0;
}