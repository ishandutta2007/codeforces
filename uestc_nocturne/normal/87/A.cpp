#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
LL a,b;
int main()
{
	while(~scanf("%lld%lld",&a,&b))
	{
		LL ti=0;
		LL ta=0;
		LL tb=0;
		LL pa=1;
		LL pb=1;
		while(1)
		{
			if(pa*a==pb*b)
			{
				if(a<b)tb+=pb*b-ti;
				else ta+=pb*b-ti;
				break;
			}
			else if(pa*a<pb*b)
			{
				ta+=pa*a-ti;
				ti=pa*a;pa+=1;
			}
			else
			{
				tb+=pb*b-ti;
				ti=pb*b;pb+=1;
			}
		}
		if(ta==tb)puts("Equal");
		else if(ta>tb)puts("Dasha");
		else puts("Masha");
	}
}