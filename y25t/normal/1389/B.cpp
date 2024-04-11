#include<cstdio>
#include<algorithm>
#define N 300005

int T;

int n,m,k,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int mx=0,sum=a[1],ans=0;
		for(int i=2;i<=m+1;i++){
			mx=std::max(mx,a[i]+a[i-1]);
			sum+=a[i];
			ans=std::max(ans,sum+std::min(k,(m-i+1)>>1)*mx);
			if((m-i+1)&1)
				ans=std::max(ans,sum+std::min(k-1,(m-i+1)>>1)*(a[i]+a[i-1])+a[i-1]);
		}
		printf("%d\n",ans);
	}
}