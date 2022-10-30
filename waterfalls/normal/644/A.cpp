#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main() {
	scanf("%d%d%d",&n,&a,&b);
	int one = (n+1)/2;
	int two = n/2;
	if (one>(a*b+1)/2) return printf("-1\n"), 0;
	if (two>a*b/2) return printf("-1\n"), 0;
	for (int i=0;i<a;i++) {
		for (int j=0;j<b;j++) {
			if ((i+j)%2==0) {
				printf("%d ",max(0,one*2-1));
				if (one) one-=1;
			} else {
				printf("%d ",two*2);
				if (two) two-=1;
			}
		}
		printf("\n");
	}

	return 0;
}