#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int n,k;
int a[100013];
int b[100013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n/k;i++) scanf("%d",&a[i]);
	for (int i=0;i<n/k;i++) scanf("%d",&b[i]);
	int ans = 1;
	for (int i=0;i<n/k;i++) {
		int cur = 1;
		for (int j=0;j<k;j++) cur*=10;
		int cur2 = cur/10;
		cur = (cur-1)/a[i]+1;
		int low = cur2*b[i]+((-cur2*b[i])%a[i]+a[i])%a[i];
		b[i]+=1;
		int high = cur2*b[i]+((-cur2*b[i])%a[i]+a[i])%a[i];
		cur-=(high-low)/a[i];
		ans = ((long long) ans*cur)%MOD;
	}
	printf("%d\n",ans);

	return 0;
}