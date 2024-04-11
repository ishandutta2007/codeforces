#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,i,lf=0,rf=0;
	scanf("%i %i %i",&n,&m,&k);
	n*=2;
	int g=__gcd(n,k);if(g!=1) lf=1;
	n/=g;k/=g;
	g=__gcd(m,k);if(g!=1) rf=1;
	m/=g;k/=g;
	if(!lf && rf) n/=2,m*=2;
	if(k==1) printf("YES\n%i %i\n%i %i\n%i %i",n,0,0,m,0,0);
	else printf("NO\n");
	return 0;
}