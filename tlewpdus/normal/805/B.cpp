#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n, i;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		printf("%c",'a'+((i/2)%2));
	}
	printf("\n");
	return 0;
}