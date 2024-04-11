#include<cstdio>
#define N 100005

int T;

int n,k,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1&&a[1]==k){
			printf("yes\n");
			continue;
		}
		bool f1=0,f2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)
				f1=1;
			if((i>1&&a[i]>=k&&a[i-1]>=k)||(i>2&&a[i]>=k&&a[i-2]>=k))
				f2=1;
		}
		if(f1&&f2)
			printf("yes\n");
		else
			printf("no\n");
	}
}