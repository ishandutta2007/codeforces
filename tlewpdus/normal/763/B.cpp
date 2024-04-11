#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int n;

int main() {
	int i;
	scanf("%d",&n);
	printf("YES\n");
	for (i=0;i<n;i++) {
		int a, b, c, d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",((min(a,c)%2+2)%2)*2+((min(b,d)%2+2)%2)+1);
	}

	return 0;
}