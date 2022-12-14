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
#define N 200005
#define ll long long
ll sum[N],t,ans,p[N];int a[N],n,s[N];
int find(int x){if(x<0)return 0;int ret=0;for(;x;x-=x&-x)ret+=s[x];return ret;}
void fix(int x){for(;x<N;x+=x&-x)s[x]++;}
int main()
{
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],p[i]=sum[i];sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(p+1,p+n+1,sum[i])-p;
	for(int i=1;i<=n;i++)
	{
		ans+=find(n)-find(upper_bound(p+1,p+n+1,sum[i]-t)-p-1)+(sum[i]<t);
		fix(a[i]);
	}printf("%lld\n",ans);
}