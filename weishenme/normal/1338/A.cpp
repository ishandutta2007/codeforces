#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int T,n,m,a[N],s[N],ans[N];
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int ans=0;
		for (int i=2;i<=n;i++)ans=max(ans,a[i-1]-a[i]),a[i]=max(a[i],a[i-1]);
		int sum=0;
		while (ans){
			ans/=2;
			sum++;
		}
		printf("%lld\n",sum);
	}
}