#include<stdio.h>
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d",&n);
		while(n){
			if(n%10>ans)
				ans=n%10;
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}