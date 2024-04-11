#include <bits/stdc++.h>
using namespace std;
long long n,x,y;
long long ABS(long long x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%lld%lld%lld",&n,&x,&y);
	if(ABS(x-1)+ABS(y-1)>ABS(x-n)+ABS(y-n)) printf("Black");
	else printf("White");
	return 0;
}