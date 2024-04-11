#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
if(a<b) swap(a,b);
return b==0?a:gcd(a%b,b);}
bool is_fin(long long a,long long bas)
{
	long long aa=gcd(a,bas);
	/*while(a!=aa)
	{
		aa=a;
		a/=gcd(a,bas);
	}*/
	while(aa!=1)
	{
		while(!(a%aa))
			a/=aa;
		aa=gcd(a,aa);
	}
	return a==1;
}
int n;
long long p,q,b;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d%I64d%I64d",&p,&q,&b);
		if(is_fin(q/gcd(p,q),b)) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}