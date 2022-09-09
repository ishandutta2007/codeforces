#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	scanf("%i %i %i",&a,&b,&c);
	int mx=max(a,max(b,c));
	int ost=a+b+c-mx;
	if(ost<=mx) printf("%i\n",mx-ost+1);
	else printf("0\n");
	return 0;
}