#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	int ans = 0;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
		int a,b;
		scanf("%d%d",&a,&b);
		ans+=a|b;
	}
	printf("%d\n",ans);

	return 0;
}