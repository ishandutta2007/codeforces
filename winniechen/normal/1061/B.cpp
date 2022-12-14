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
#define N 100005
ll n,m,a[N],ans,mn,p[N],hav[N];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),ans+=a[i];sort(a+1,a+n+1);
	mn=1;
	for(int i=1;i<=n;i++)
		if(a[i]>=mn)mn++;
	ans-=n+a[n]-mn+1;
	printf("%lld\n",ans);
}