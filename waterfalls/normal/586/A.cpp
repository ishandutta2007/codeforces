#include <bits/stdc++.h>
using namespace std;

int n;
int a[1013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans = 0;
	for (int i=1;i<=n;i++) if (a[i] || (a[i-1] && a[i+1])) ans+=1;
	printf("%d\n",ans);

	return 0;
}