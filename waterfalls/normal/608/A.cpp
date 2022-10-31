#include <bits/stdc++.h>
using namespace std;

int n,s;

int main() {
	scanf("%d%d",&n,&s);
	int ans = s;
	for (int i=0;i<n;i++) {
		int t,f;
		scanf("%d%d",&t,&f);
		ans = max(ans,t+f);
	}
	printf("%d\n",ans);

	return 0;
}