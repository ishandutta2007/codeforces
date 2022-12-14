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
ll n,ans[1000005];
int tot;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans[++tot]=(2+n-i)*(n/i)>>1;
			ans[++tot]=(2+n-(n/i))*i>>1;
		}
	}
	sort(ans+1,ans+tot+1);
	tot=unique(ans+1,ans+tot+1)-ans-1;
	for(int i=1;i<=tot;i++)printf("%lld ",ans[i]);puts("");
}