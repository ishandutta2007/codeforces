#include<stdio.h>
int main(){
	int n, i;
	int ans = 10000000;
	scanf("%d", &n);
	for(int i=1; i*i <= n; i++){
		int a = n/i;
		if(n%i != 0) a++;
		int t = (a+i)*2;
		if(t < ans) ans = t;
	}
	printf("%d\n", ans);
	return 0;
}