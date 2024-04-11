#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
int n,x,y;ll a,b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n<<1;i++)
	{
		scanf("%d%d",&x,&y);
		a+=x,b+=y;
	}
	printf("%lld %lld\n",a/n,b/n);
}