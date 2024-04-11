#include <bits/stdc++.h>
using namespace std;

int n;
int a[1013];
int b[1013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=0;i<n-n/2;i++) {
		b[2*i] = a[i];
	}
	for (int i=n-n/2;i<n;i++) {
		b[(i-n+n/2)*2+1] = a[i];
	}
	for (int i=0;i<n;i++) printf("%d ",b[i]);
	printf("\n");

	return 0;
}