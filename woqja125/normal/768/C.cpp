#include<stdio.h>
#include<algorithm>
int max(int a, int b){ return a>b?a:b; }
int c[2][1030];
int main(){
	int n, k, x, t, b=1;
	scanf("%d%d%d", &n, &k, &x);
	for(int i=1; i<=n; i++){
		scanf("%d", &t);
		c[0][t]++;
	}
	for(int i=0; i<k; i++){
		int *s = c[i%2];
		int *d = c[(i+1)%2];
		b = 1;
		for(int j=0; j<=1024; j++){
			d[j^x] += (s[j]+b)/2;
			d[j] += s[j] - (s[j]+b)/2;
			b = (b+s[j])%2;
			s[j] = 0;
		}
	}
	for(int i=1024; i>=0; i--) if(c[k%2][i]){
		printf("%d ", i);
		break;
	}
	for(int i=0; i<=1024; i++) if(c[k%2][i]){
		printf("%d ", i);
		break;
	}
	return 0;
}