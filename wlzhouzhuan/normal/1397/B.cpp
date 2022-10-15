#include<bits/stdc++.h>
#define LONG_LONG_MAX 0x7fffffffffffffff
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N],ans=LONG_LONG_MAX;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)	
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int t=pow(LONG_LONG_MAX,1.0/n);
	for(int i=1;i<=t;i++){
		int sum=0,tmp=1;
		for(int j=1;j<=n;j++)
			sum+=abs(tmp-a[j]),tmp*=i;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}