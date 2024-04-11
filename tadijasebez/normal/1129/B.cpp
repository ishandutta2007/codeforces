#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=1000000;i++) if((n+i)%2000==0 && (n+i)/2000<i) break;
	printf("2000\n");
	for(j=1;j<=1998;j++) printf("0 ");
	printf("%i %i\n",(n+i)/2000-i,i);
	return 0;
}