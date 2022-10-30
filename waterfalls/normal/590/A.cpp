#include <bits/stdc++.h>
using namespace std;

int n;
int a[500013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans = 0;
	a[0] = a[1];
	a[n+1] = a[n];
	int e = 0;
	for (int i=1;i<=n+1;i++) {
		if (a[i]==a[i-1]) {
			int len = i-e;
			ans = max(ans,(len-1)/2);
			if (len%2==0) {
				for (int j=e;j<e+len/2;j++) a[j] = a[e];
				for (int j=e+len/2;j<i;j++) a[j] = a[i-1];
			} else for (int j=e;j<i;j++) a[j] = a[i-1];
			e = i;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");

	return 0;
}