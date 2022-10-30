#include <bits/stdc++.h>
using namespace std;

int n;
int x[200013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	int vgets = (n-2+1)/2;
	int ans = 1e9;
	for (int i=0;i<=vgets;i++) ans = min(ans,x[n-(vgets-i)]-x[i+1]);
	printf("%d\n",ans);

	return 0;
}