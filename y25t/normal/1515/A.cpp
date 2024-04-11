#include<cstdio>
#include<algorithm>
#define N 105

int T;

int n,k,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum==k){
			puts("NO");
			continue;
		}
		puts("YES");
		sum=0;
		bool flg=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum==k&&!flg){
				std::swap(a[i],a[i+1]);
				flg=1;
			}
			printf("%d ",a[i]);
		}
		puts("");
	}
}