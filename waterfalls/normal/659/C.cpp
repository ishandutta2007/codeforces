#include <bits/stdc++.h>
using namespace std;

int n,m;
set<int> has;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		has.insert(x);
	}
	vector<int> ans;
	for (int i=1;i<=m;i++) {
		if (!has.count(i)) {
			ans.push_back(i);
			m-=i;
		}
	}
	printf("%d\n",ans.size());
	for (int i: ans) printf("%d ",i);
	printf("\n");

	return 0;
}