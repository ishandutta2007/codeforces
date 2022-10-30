#include <bits/stdc++.h>
using namespace std;

int n;
int a[113];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int ans = 0;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			swap(a[i],a[j]);
			ans = max(ans,abs(max_element(a,a+n)-min_element(a,a+n)));
			swap(a[i],a[j]);
		}
	}
	printf("%d\n",ans);

	return 0;
}