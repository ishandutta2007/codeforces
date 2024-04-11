#include <bits/stdc++.h>

using namespace std;

int n;
int h[100013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&h[i]);
	int prev = -1;
	for (int i=n-1;i>=0;i--) {
		int prev2 = h[i];
		h[i] = max(0,prev+1-h[i]);
		prev = max(prev,prev2);
	}
	for (int i=0;i<n;i++) printf("%d ",h[i]);
	printf("\n");

	return 0;
}