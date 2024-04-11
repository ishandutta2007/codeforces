#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	scanf("%i",&n);
	int a=n/3,b=n-a;
	for(i=1;i<=b;i++) printf("1 %i\n",i);
	for(i=1;i<=a;i++) printf("4 %i\n",i*2);
	return 0;
}