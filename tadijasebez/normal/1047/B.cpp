#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y,mx=0;
	scanf("%i",&n);
	while(n--) scanf("%i %i",&x,&y),mx=max(mx,x+y);
	printf("%i\n",mx);
	return 0;
}