#include<bits/stdc++.h>
using namespace std;
int main()
{
	double m,n,a,b;
	cin>>m>>n>>a>>b;
	printf("%.0lf",ceil(ceil(n/a)*m/b));
	return 0;
}