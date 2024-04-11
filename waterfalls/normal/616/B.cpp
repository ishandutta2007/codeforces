#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	int ans = 0;
	for (int i=0;i<n;i++) {
		int high = 1e9+7;
		for (int j=0;j<m;j++) {
			int c;
			scanf("%d",&c);
			high = min(high,c);
		}
		ans = max(ans,high);
	}
	printf("%d\n",ans);

	return 0;
}