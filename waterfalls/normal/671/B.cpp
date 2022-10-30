#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
int a[500013];

bool check(int t, int w) {
	ll tot = 0;
	for (int i=0;i<n;i++) {
		tot+=max(0,w*(a[i]-t));
	}
	return tot<=k;
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int low = 0, high = 1e9+7;
	while (high-low>1) {
		if (check((low+high+1)/2,1)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	int top = high;
	low = 0, high = 1e9+7;
	while (high-low>1) {
		if (check((low+high)/2,-1)) low = (low+high)/2;
		else high = (low+high)/2;
	}
	int bot = low;
	if (bot>=top) return printf("%d\n",accumulate(a,a+n,0LL)%n>0), 0;
	printf("%d\n",top-bot);

	return 0;
}