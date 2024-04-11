#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long n; 
int main()
{
	scanf("%lld",&n);
	n=n*(n+1)/2;
	if(n&1)
	{
		printf("1");
	}
	else
	{
		printf("0"); 
	}
	return 0;
}
//ee