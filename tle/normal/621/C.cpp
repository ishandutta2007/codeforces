#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n;
double g=0;
long long p,l[233333],r[233333];
double pg(long long l,long long r)
{
	return (r/p-(l-1)/p)/double(r-l+1);
}
int main()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	for(int i=1;i<=n;i++)
	{
		double g1=pg(l[i],r[i]),g2=pg(l[i%n+1],r[i%n+1]);
		g+=(1-(1-g1)*(1-g2))*2000;
	}
	printf("%.10lf\n",g);
}