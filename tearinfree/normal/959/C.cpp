#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	if(n<=5) {
		puts("-1");
	}
	else {
		printf("1 2\n2 3\n2 4\n4 5\n");
		for(int i=6;i<=n;i++) printf("%d %d\n",4,i);
	}
	for(int i=1;i<n;i++) printf("%d %d\n",i,i+1);
	return 0;
}