#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int p[300013], where[300013];
int far[300013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%d",&p[i]);
		where[p[i]] = i;
		far[i] = -1;
	}
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (where[a]>where[b]) swap(a,b);
		far[where[b]] = max(far[where[b]],where[a]);
	}
	ll ans = 0;
	int r = -1;
	for (int l=0;l<n;l++) {
		while (r<n-1 && far[r+1]<l) r++;
		ans+=r-l+1;
	}
	printf("%lld\n",ans);

	return 0;
}