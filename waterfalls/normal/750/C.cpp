#include <bits/stdc++.h>
using namespace std;

int n;
int c[200013], d[200013];

int main() {
	scanf("%d",&n);
	for (int i=n;i>=1;i--) {
		scanf("%d%d",&c[i],&d[i]);
	}
	int low = -1e9;
	int high = 1e9;
    int cur = 0;
    for (int i=1;i<=n;i++) {
		cur+=c[i];
		if (d[i]==1) {
			low = max(low,cur);
		} else {
			high = min(high,cur-1);
		}
    }
    if (low>high) printf("Impossible\n");
    else if (high>1e8) printf("Infinity\n");
    else printf("%d\n",high+1900);

	return 0;
}