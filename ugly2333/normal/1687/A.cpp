//CF1687A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,k,a[N];
LL s[N],ans;
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s[i]=s[i-1]+a[i];
		ans=0;
		for(i=1;i<=n;i++)
			ans=max(ans,s[i]-s[max(i-k,0)]);
		ans+=(LL)k*(k-1)/2;
		if(k>n)
			ans-=(LL)(k-n)*(k-n-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}