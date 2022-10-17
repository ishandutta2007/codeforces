#include<stdio.h>
#include<math.h>
#include<vector>
#define int long long
using namespace std;
const int maxn=100005;
int T,n,tot0,tot1;
vector<int>v0,v1;
int a[maxn];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n),tot0=tot1=0,v0.clear(),v1.clear();
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]%2==0)
				tot0++,v0.push_back(i);
			else tot1++,v1.push_back(i);
		}
		if(abs(tot0-tot1)>1){
			puts("-1");
			continue;
		}
		int cnt0=0,cnt1=0;
		if(tot0>=tot1){
			for(int i=1;i<=n;i+=2)
				cnt0+=abs(v0[(i-1)/2]-i);
			for(int i=2;i<=n;i+=2)
				cnt0+=abs(v1[i/2-1]-i);
		}
		if(tot1>=tot0){
			for(int i=1;i<=n;i+=2)
				cnt1+=abs(v1[(i-1)/2]-i);
			for(int i=2;i<=n;i+=2)
				cnt1+=abs(v0[i/2-1]-i);
		}
		cnt0>>=1,cnt1>>=1;
		if(tot0==tot1)
			printf("%lld\n",min(cnt0,cnt1));
		if(tot0>tot1)
			printf("%lld\n",cnt0);
		if(tot0<tot1)
			printf("%lld\n",cnt1);
	}
	return 0;
}