#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[1013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) for (int r=0;r<3;r++) {
		int a;
		scanf("%d",&a);
		if (a) cnt[i]+=1;
	}
	int ans = 0;
	for (int i=0;i<n;i++) ans+=cnt[i]>=2;
	printf("%d\n",ans);

	return 0;
}