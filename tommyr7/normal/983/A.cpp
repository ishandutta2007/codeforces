#include <bits/stdc++.h>
using namespace std;
int n;
long long a,b,c;
long long gcd(long long a,long long b)
{
	if (a==0) return b;
	if (b==0) return a;
	return gcd(b,a%b);
}
bool check(long long a,long long b)
{
	if (a==b) return true;
	if (a==1) return true;
	if (b==1) return false;
	return check(a/gcd(a,b),gcd(a,b));
}
int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		b=b/gcd(a,b);
		if (a==0) printf("Finite\n");
		else if (check(b,c)) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}