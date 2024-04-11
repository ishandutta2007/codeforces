#include <bits/stdc++.h>
using namespace std;

int n;
set<int> has;
int l[300013], r[300013];

int main() {
	scanf("%d",&n);
	int ans = 0;
	int prev = 1;
	for (int i=1;i<=n;i++) {
		int a;
		scanf("%d",&a);
		if (has.count(a)) {
			l[ans] = prev;
			r[ans] = i;
			prev = i+1;
			ans+=1;
			has.clear();
		} else has.insert(a);
	}
	if (ans==0) return printf("-1\n"), 0;
	r[ans-1] = n;
	printf("%d\n",ans);
	for (int i=0;i<ans;i++) printf("%d %d\n",l[i],r[i]);

	return 0;
}