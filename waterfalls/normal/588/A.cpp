#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	int cur = 1e9;
	scanf("%d",&n);
	int ans = 0;
	for (int i=0;i<n;i++) {
		int a,p;
		scanf("%d%d",&a,&p);
		cur = min(cur,p);
		ans+=cur*a;
	}
	printf("%d\n",ans);

	return 0;
}