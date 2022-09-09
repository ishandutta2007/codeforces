#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,d;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&d);
		ll D=(ll)d*d-4*d;
		if(D<0){ printf("N\n");continue;}
		double a=(double)(-d-sqrt(D))/(-2);
		double b=d-a;
		printf("Y ");
		cout<<fixed<<setprecision(12)<<abs(a)<<" "<<abs(b)<<"\n";
	}
	return 0;
}