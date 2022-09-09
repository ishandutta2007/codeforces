#include <bits/stdc++.h>
using namespace std;
map<int,double> C;
long double sol=0,sum=0;
int main()
{
	int n,i;
	long long x;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&x);
		sol=sol+x*i-sum+C[x+1]-C[x-1];
		C[x]=C[x]+1;
		sum=sum+x;
	}
	cout << fixed << setprecision(0) << sol << endl;
	return 0;
}