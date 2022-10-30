#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int prev = 0;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		if (t>prev+15) return printf("%d\n",prev+15), 0;
		prev = t;
	}
	if (90>prev+15) return printf("%d\n",prev+15), 0;
	printf("90\n");

	return 0;
}