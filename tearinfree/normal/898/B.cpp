#include <cstdio>
int main() {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i*b<=a;i++) {
		if( (a-i*b)%c==0 ) {
			printf("YES\n%d %d\n",i,(a-i*b)/c);
			return 0;
		}
	}
	puts("NO");
}