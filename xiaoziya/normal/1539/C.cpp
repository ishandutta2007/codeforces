#include<stdio.h>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=200005;
int n,k,x,bs,ans;
int a[maxn],b[maxn];
signed main(){
	scanf("%lld%lld%lld",&n,&k,&x),ans=n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>x)
			b[++bs]=(a[i]-a[i-1]+x-1)/x-1;
		else ans--;
	}
	sort(b+1,b+1+bs);
	for(int i=1;i<=bs;i++){
		k-=b[i];
		if(k>=0)
			ans--;
	}
	printf("%lld\n",ans);
	return 0;
}