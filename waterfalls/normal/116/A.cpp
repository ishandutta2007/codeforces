#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	int ans = 0;
	int cur = 0;
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		cur-=a;
		cur+=b;
		ans = max(ans,cur);
	}
	printf("%d\n",ans);

	return 0;
}