#include<stdio.h>
int main(){
	int n;
	long long k, s=0;
	scanf("%d%lld", &n, &k);
	if(k > 1ll*n*(n-1)/2){
		printf("Impossible\n");
		return 0;
	}
	int i, r;
	for(i=1; i<n; i++){
		if(s+i > k){
			r = k - s;
			break;
		}
		s+=i;
	}
	i--;
	printf("(");
	for(int j=1; j<=i; j++){
		if(j==r) printf("()");
		printf("(");
	}
	for(int j=0; j<=i; j++) printf(")");
	if(r) i++;
	for(i++; i<n; i++) printf("()");
	printf("\n");
	return 0;
}