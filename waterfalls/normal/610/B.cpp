#include <bits/stdc++.h>
using namespace std;

int n;
int a[400013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) a[i+n] = a[i];
	int low = *min_element(a,a+n);
	int res = 0;
	for (int i=0;i<n;i++) if (a[i]==low) {
		int len = 0;
		while (a[i+1]>low) len+=1, i+=1;
		res = max(res,len);
	}
	printf("%lld\n",(long long) low*n+res);

	return 0;
}