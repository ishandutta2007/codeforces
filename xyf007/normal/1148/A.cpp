#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
long long a,b,c;
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld",c*2+std::min(a,b)+std::min(std::min(a,b)+1,std::max(a,b)));
	return 0;
}