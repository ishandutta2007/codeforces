#include<stdio.h>
int p[100010];
int main(){
	int n;
	scanf("%d", &n);
	if(n==1){
		printf("1\n1");
		return 0;
	}
	if(n==2){
		printf("1\n1 1");
		return 0;
	}
	printf("2\n");
	for(int i=2; i<=n+1; i++){
		printf("%d ", p[i]+1);
		if(p[i] == 0){
			for(long long j=1ll*i*i; j<=n+1; j+=i) p[j] = 1;
		}
	}
	return 0;
}