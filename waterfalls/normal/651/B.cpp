#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int> cnt;

int main() {
	scanf("%d",&n);
	int ans = n;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		cnt[x]+=1;
		ans = min(ans,n-cnt[x]);
	}
	printf("%d\n",ans);

	return 0;
}