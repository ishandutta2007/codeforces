#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
pair<int,int> a[100013];
int ans[100013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&a[i].A,&a[i].B);
	}
	sort(a,a+n);
	for (int i=0;i<n;i++) {
		int dest = lower_bound(a,a+n,MP(a[i].A-a[i].B,0))-a;
		if (dest==i) ans[i] = i ? ans[i-1] : 0;
		else ans[i] = (dest ? ans[dest-1] : 0)+i-dest;
	}
	int res = 1e9;
	for (int i=0;i<n;i++) {
		int cur = n-i;
		if (i) cur+=ans[i-1];
		res = min(res,cur);
	}
	res = min(res,ans[n-1]);
	printf("%d\n",res);

	return 0;
}