//CF1656B
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
LL s,ans,a[N],t,n,k;
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
			scanf("%lld",a+i);
		sort(a+1,a+n+1);
		s=0;
		for(i=1;i<=n;i++)
			s+=a[i];
		if(s+(LL)(n-2)*a[1]>0||s+(LL)(n-2)*a[n]<0){
			printf("INF\n");
			continue;
		}
		if(a[n]==a[1]){
			printf("0\n");
			continue;
		}
		s+=(n-2)*a[n];
		k=s/(a[n]-a[1]);
		t=-a[n-k-1];
		ans=-(LL)t*t*(n-1);
		for(i=1;i<=n;i++)
			a[i]+=t;
		ans+=(LL)a[1]*a[n];
		for(i=2;i<n;i++)
			ans+=min((LL)a[i]*a[1],(LL)a[i]*a[n]);
		printf("%lld\n",ans);
	}
	return 0;
}