#include <bits/stdc++.h>
using namespace std;
long long n,m; 
int main()
{
	scanf("%lld%lld",&n,&m);
	printf("%lld",(long long)ceil(m/(long double)n));
	return 0;
}