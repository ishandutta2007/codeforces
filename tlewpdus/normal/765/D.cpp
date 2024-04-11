#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>

using namespace std;

int n;
int f[100100];
int g[100100];
int h[100100];

int main() {
	int i, m = 0;

	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&f[i]);
	for (i=1;i<=n;i++) {
		if (f[i]==i) {
			g[i] = ++m;
			h[m] = i;
		}
	}
	bool flag = true;
	for (i=1;i<=n;i++) {
		if (!g[i]) {
			if (f[f[i]]!=f[i]) flag = false;
			else g[i] = g[f[i]];
		}
	}
	if (!flag) printf("-1\n");
	else {
		printf("%d\n",m);
		for (i=1;i<=n;i++) printf("%d ",g[i]);
		printf("\n");
		for (i=1;i<=m;i++) printf("%d ",h[i]);
		printf("\n");
	}
	return 0;
}