#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int p[500013];
char s[500013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&p[i]);
	scanf(" %s",&s);
	ll ans = 0;
	ll cur = 0;
	for (int i=0;i<n;i++) {
		if (s[i]=='A') cur+=p[i];
		else cur-=p[i];
		ans = max(ans,cur);
	}
	cur = 0;
	for (int i=n-1;i>=0;i--) {
		if (s[i]=='A') cur+=p[i];
		else cur-=p[i];
		ans = max(ans,cur);
	}
	for (int i=0;i<n;i++) if (s[i]=='B') ans+=p[i];
	printf("%lld\n",ans);

	return 0;
}