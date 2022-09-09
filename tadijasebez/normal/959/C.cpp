#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int

int main()
{
	int n,i;
	scanf("%i",&n);
	if(n<6) printf("-1\n");
	else
	{
		int sz=(n+1)/2;
		for(i=2;i<=sz;i++) printf("1 %i\n",i);
		printf("%i %i\n",1,sz+1);
		for(i=sz+2;i<=n;i++) printf("%i %i\n",sz+1,i);
	}
	for(i=1;i<n;i++) printf("%i %i\n",i,i+1);
	return 0;
}