#include<cstdio>
#define N 105

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				a[i]++;
				ans++;
			}
			sum+=a[i];
		}
		if(!sum)
			ans++;
		printf("%d\n",ans);
	}
}