#include <bits/stdc++.h>
using namespace std;
int n; 
int main()
{
	scanf("%d",&n);
	printf("1 ");
	n-=1;
	if((n-2)%3!=0) printf("2 %d",n-2);
	else if((n-2)%3==1) printf("2 %d",n-2);
	else printf("1 %d",n-1);
	return 0;
}