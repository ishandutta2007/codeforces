#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int k,n,s,p;
	scanf("%i %i %i %i",&k,&n,&s,&p);
	int sol=(n+s-1)/s*k;
	sol=(sol+p-1)/p;
	printf("%i\n",sol);
	return 0;
}