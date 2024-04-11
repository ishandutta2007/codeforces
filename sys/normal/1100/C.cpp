#include <bits/stdc++.h>
using namespace std;
int n,r;
const double pi=3.1415926535897932384626;
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d%d",&n,&r);
	long double y=sqrt(r*r*(2-2*cos(2*pi/n)));
	printf("%.10Lf",y/(2-y/r));
	return 0;
}