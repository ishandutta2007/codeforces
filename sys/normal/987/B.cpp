#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	if(a>powl(b,a/(long double)b)) printf(">");
	else if(a==powl(b,a/(long double)b)) printf("=");
	else printf("<");
	return 0;
}