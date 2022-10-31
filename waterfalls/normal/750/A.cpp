#include <bits/stdc++.h>
using namespace std;

int n,k;

int main() {
	scanf("%d%d",&n,&k);
	k = 240-k;
	int ans = 0;
	while (n) {
		if (k<(ans+1)*5) break;
		k-=(ans+1)*5;
		n-=1;
		ans+=1;
	}
	printf("%d\n",ans);

	return 0;
}