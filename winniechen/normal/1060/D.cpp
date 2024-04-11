#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 100005
#define ll long long
int n,a[N],b[N];ll ans;
int main()
{
	scanf("%d",&n);ans=n;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)ans+=max(a[i],b[i]);
	printf("%lld\n",ans);
}