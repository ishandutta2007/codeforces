#include<cstdio>
#include<algorithm>
#define ll long long
#define N 400005

int T;

int n,a[N];

ll ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1])
				ans+=a[i]-a[i-1];
			if(a[i]>a[i+1])
				ans+=a[i]-a[i+1];
		}
		for(int i=1;i<=n;i++)
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				ans-=a[i]-std::max(a[i-1],a[i+1]);
			}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			a[i]=0;
	}
}