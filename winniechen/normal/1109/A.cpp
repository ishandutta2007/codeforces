#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
int n,a[N],s[N],b[1<<20][2];
ll ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=a[i]^s[i-1];b[0][0]++;
	for(int i=1;i<=n;i++)
	{
		int p=i&1;
		ans+=b[s[i]][p];
		b[s[i]][p]++;
	}
	printf("%lld\n",ans);
}