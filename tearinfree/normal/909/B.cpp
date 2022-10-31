#include <cstdio>
#include <algorithm>
#include <cstring>

int n;
int cache[101];
int main() {
	scanf("%d",&n);
	
	int sum=0;
	if(n%2==1) {
		while(n>1) {
			sum+=(n/2)*2+1;
			n-=2;
		}
		printf("%d\n",sum+1);
	}
	else {
		while(n>1) {
			sum+=((n-1)/2*2)+2;
			n-=2;
		}
		printf("%d\n",sum);
	}
	return 0;
}