#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int min(int a, int b)
{
	if(a>b) return b;
	return a;
}
int main()
{
	int n,k,i,a;
	int mass=0;
	int sol=0,soli=-1;
	scanf("%i %i",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%i",&a);
		mass+=a;
		sol+=min(mass,8);
		mass-=min(mass,8);
		if(soli==-1 && sol>=k){ soli=i+1;}
	}
	printf("%i\n",soli);
	return 0;
}