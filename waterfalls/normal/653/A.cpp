#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	vector<int> t(n);
	for (int i=0;i<n;i++) scanf("%d",&t[i]);
	for (int i: t) {
		for (int j: t) {
			for (int k: t) {
				vector<int> has = {i,j,k};
				sort(has.begin(),has.end());
				has.erase(unique(has.begin(),has.end()),has.end());
				if (has.size()==3 && has[2]-has[0]<=2) return printf("YES\n"), 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}