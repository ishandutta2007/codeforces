#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(b-a>10) printf("0\n");
	else
	{
		int sol=1;
		for(a++;a<=b;a++)
		{
			int x=a%10;
			sol=(sol*x)%10;
		}
		printf("%i\n",sol);
	}
	return 0;
}