#include <bits/stdc++.h>
using namespace std;

int n;
int a[1013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int has = 0;
	int ans = 0;
	while (true) {
		for (int i=0;i<n;i++) if (a[i]<=has) a[i] = 1e9, has+=1;
		if (has==n) return printf("%d\n",ans), 0;
		ans+=1;
		for (int i=n-1;i>=0;i--) if (a[i]<=has) a[i] = 1e9, has+=1;
		if (has==n) return printf("%d\n",ans), 0;
		ans+=1;
	}

	return 0;
}