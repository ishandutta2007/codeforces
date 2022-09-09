#include <bits/stdc++.h>

using namespace std;

int n, k, m;

void print(int d) {
	int i, j, p = m+3, q = d, rem = m-d+1;
	for (i=1;i<=d;i++) {
		if (i==1) printf("%d %d\n",i,m+1);
		else if (i==d) printf("%d %d\n",i-1,m+2);
		else printf("%d %d\n",i,i-1);
	}
	// d/2
	for (;p<=n;p++) {
		int num = min(rem,d/2-1);
		if (num==0) {
			printf("%d %d\n",d/2,p);
		}
		else {
			for (j=0;j<=num;j++) {
				if (j==0) {printf("%d %d\n",d/2,q);q++;}
				else if (j==num) printf("%d %d\n",q-1,p);
				else {printf("%d %d\n",q-1,q);q++;}
			}
		}
		rem -= num;
	}
}

bool ok(int d) {
	return (k-2)*(d/2-1)+(d-1)>=m;
}

int main() {
	int i;

	scanf("%d%d",&n,&k);
	m = n-k;
	for (i=2;i<=n-1;i++) {
		if (ok(i)) {
			printf("%d\n",i);
			print(i);
			break;
		}
	}

    return 0;
}