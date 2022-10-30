#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int prev = 2e9;
	int ans = 0;
	int cur = 0;
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		if (a>=prev) cur+=1;
		else cur = 1;
		prev = a;
		ans = max(ans,cur);
	}
	printf("%d\n",ans);

	return 0;
}