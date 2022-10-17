#include<stdio.h>
int T,n,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if((a+b)&1){
			puts("-1");
			continue;
		}
		if(a==0&&b==0)
			puts("0");
		else if(a==b)
			puts("1");
		else puts("2");
	}
	return 0;
}