#include<cstdio>
#include<algorithm>
#define ll long long
#define N 200005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ll ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]<a[i-1])
				ans+=a[i-1]-a[i];
		printf("%I64d\n",ans);
	}
}