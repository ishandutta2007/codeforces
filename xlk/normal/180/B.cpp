#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,g,c;
int main()
{
	scanf("%d%d",&n,&m);
	while((g=__gcd(n,m))>1)
		m/=g,c++;
	if(m==1)
		printf("2-type\n%d",c);
	else if(!c&&n%m==1)
		puts("3-type");
	else if(!c&&n%m==m-1)
		puts("11-type");
	else if((n-1)*(n+1)/(n%2+1)%m==0)
		puts("6-type");
	else
		puts("7-type");
	return 0;
}