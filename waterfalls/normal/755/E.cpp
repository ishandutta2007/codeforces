#include <bits/stdc++.h>
using namespace std;

int n,k;

int main() {
	scanf("%d%d",&n,&k);
	if (k!=2 && k!=3) return printf("-1\n"), 0;
	if (n<=3) return printf("-1\n"), 0;
	if (n==4 && k==2) return printf("-1\n"), 0;
	if (n==5 && k==3) {
		printf("4\n");
		printf("1 2\n");
		printf("2 3\n");
		printf("3 4\n");
		printf("2 5\n");
		return 0;
	}
	if (k==2 || n==4) {
		printf("%d\n",n-1);
		for (int i=1;i<n;i++) printf("%d %d\n",i,i+1);
	} else if (k==3) {
		printf("%d\n",n-1);
		printf("1 2\n");
		printf("2 3\n");
		printf("3 4\n");
        for (int i=5;i<n;i++) printf("%d %d\n",3,i);
        printf("2 %d\n",n);
	}

	return 0;
}