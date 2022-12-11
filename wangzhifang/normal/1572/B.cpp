#include <cstdio>
#define il __inline__ __attribute__((always_inline))
using namespace std;
#define max_n 200000
int a[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	int pos=0;
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		a[i]^=a[i-1];
		if((i&1)&&!a[i])
			pos=i;
	}
	if(pos&&!a[n]){
		printf("YES\n%d\n",n-1-int(n!=pos));
		for(int i=pos+1; i+2<=n; i+=2)
			printf("%d ",i);
		for(int i=pos; (i-=2)>=1; printf("%d ",i));
		for(int i=1; i+2<=n; i+=2)
			printf("%d ",i);
		putchar('\n');
	}
	else
		puts("NO");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}