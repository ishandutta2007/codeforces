#include <bits/stdc++.h>
using namespace std;

int n;
int a[200013], b[200013];

int main() {
	scanf("%d",&n);
	for (int i=0, on=0;i<n;i++, on+=(a[on]>0)) scanf("%d",&a[on]);
	for (int i=0, on=0;i<n;i++, on+=(b[on]>0)) scanf("%d",&b[on]);
	n-=1;
	rotate(a,find(a,a+n,1),a+n);
	rotate(b,find(b,b+n,1),b+n);
	for (int i=0;i<n;i++) if (a[i]!=b[i]) return printf("NO\n"), 0;
	printf("YES\n");

	return 0;
}