#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
ll n,m;
ll a,b;
ll tt;
ll mm;
int main()
{
	scanf("%lld%lld",&n,&m);
	tt=(n*n+1)/2;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a,&b);
		mm=(a-1)*n+b;
		mm=(mm+1)/2;
		if(!((a+b)&1))printf("%lld\n",mm);
		else printf("%lld\n",mm+tt);
	}
}