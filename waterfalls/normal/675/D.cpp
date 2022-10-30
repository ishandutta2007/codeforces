#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int> pos;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		pos[x] = i;
		auto it = pos.find(x);
		int ans = 0;
		int which = 0;
		if (it!=pos.begin()) {
			if (prev(it)->second > which) {
				ans = prev(it)->first;
				which = prev(it)->second;
			}
		}
		if (next(it)!=pos.end()) {
			if (next(it)->second > which) {
				ans = next(it)->first;
				which = next(it)->second;
			}
		}
		if (which) printf("%d ",ans);
	}
	printf("\n");

	return 0;
}