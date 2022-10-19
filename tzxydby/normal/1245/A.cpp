#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		puts(__gcd(a,b)==1?"Finite":"Infinite");
	}
	return 0;
}