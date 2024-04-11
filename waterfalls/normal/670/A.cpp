#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int low = 1e9, high = 0;
	for (int i=0;i<7;i++) {
		int cur = 0;
		for (int j=0;j<n;j++) {
			if ((j+i)%7<2) cur+=1;
		}
		low = min(low,cur);
		high = max(high,cur);
	}
	printf("%d %d\n",low,high);

	return 0;
}