#include<stdio.h>
#define moder 1000000007
const long long N = 100010;
long long power(long long a,long long x)
{
	long long i = 0,j,ans = 1;
	bool flag[60];
	while (x)
	{
		flag[i++] = x % 2;
		x /= 2;
	}
	for (j = 0; j < i; j++)
	{
		if (flag[j])
			ans = a * ans % moder;
		a = a * a % moder;
	}
	return ans;
}
int main()
{
	long long k,b,i,j,p = 2,q,f = -1;
	scanf("%I64d",&k);
	for (i = 0;i < k;i++)
	{
		scanf("%I64d",&b);
		if (! (b % 2))
			f = 1;
		p = power(p,b);
	}
	q = p * power(2,moder-2) % moder;
	p = (q + f) * power(3,moder-2) % moder;
	printf("%I64d/%I64d",p,q);
	return 0;
}