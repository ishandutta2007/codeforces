#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=2230;i++)
	{
		if(i==2230) printf("5");
		else if(i&1) printf("4");
		else printf("5");
	}
	printf("\n");
	for(i=1;i<=2230;i++)
	{
		if(i==2230) printf("5");
		else if(i&1) printf("5");
		else printf("4");
	}
	printf("\n");
	return 0;
}