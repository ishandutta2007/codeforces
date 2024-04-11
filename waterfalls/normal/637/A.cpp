#include <bits/stdc++.h>
using namespace std;

int n;
int has[1000013];

int main() {
	int ans = 0;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		has[x]+=1;
		if (has[x]>has[ans]) ans = x;
	}
	printf("%d\n",ans);

	return 0;
}