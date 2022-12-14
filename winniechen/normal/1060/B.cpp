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
ll n,tmp,x,ans;
int main()
{
	scanf("%lld",&n);
	for(tmp=9;tmp<=n;tmp=tmp*10+9)ans+=9;tmp=tmp/10;
	for(x=tmp+1+tmp;x<=n;x+=tmp+1)ans++;x-=tmp+1;x=n-x;
	while(x)ans+=x%10,x/=10;
	printf("%lld\n",ans);
}