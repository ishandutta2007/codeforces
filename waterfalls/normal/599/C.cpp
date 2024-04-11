#include <bits/stdc++.h>
using namespace std;

int n;
int h[100013];
int l[100013];
int r[100013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	h[n+1] = r[n+1] = 1e9+2;
	for (int i=1;i<=n;i++) l[i] = max(l[i-1],h[i]);
	for (int i=n;i>=1;i--) r[i] = min(r[i+1],h[i]);
	int ans = 1;
	for (int i=2;i<=n;i++) if (r[i]>=l[i-1]) ans+=1;
	printf("%d\n",ans);

	return 0;
}