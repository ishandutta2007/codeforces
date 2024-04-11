#include <bits/stdc++.h>
using namespace std;

int n,h;

int main() {
	scanf("%d%d",&n,&h);
	int ans = n;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		ans+=x>h;
	}
	printf("%d\n",ans);

	return 0;
}