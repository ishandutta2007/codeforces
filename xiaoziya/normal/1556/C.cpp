#include<stdio.h>
#define int long long
#define inf 100000000000000000
const int maxn=1005;
int n,ans;
int a[maxn];
inline int min(int a,int b){
	return a<b? a:b;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i+=2){
		int sum=0,minn=0;
		for(int j=i+1;j<=n;j++){
			if(sum<minn)
				minn=sum;
			if(j%2==0){
				int l=-minn,r=sum+l;
				if(l<=a[i]&&r<=a[j]){
					ans+=min(a[i]-l+1,a[j]-r+1);
					if(l==0&&r==0)
						ans--;
				}
			}
			sum+=j%2==0? -a[j]:a[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}