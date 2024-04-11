#include <bits/stdc++.h>
using namespace std;

int n;
int one[113];
int two[113];
int acr[113];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) scanf("%d",&one[i]);
	for (int i=0;i<n-1;i++) scanf("%d",&two[i]);
	for (int i=0;i<n;i++) scanf("%d",&acr[i]);
	vector<int> has;
	for (int i=0;i<n;i++) {
		int cur = 0;
		for (int j=0;j<i;j++) cur+=one[j];
		cur+=acr[i];
		for (int j=i;j<n-1;j++) cur+=two[j];
		has.push_back(cur);
	}
	sort(has.begin(),has.end());
	printf("%d\n",has[0]+has[1]);

	return 0;
}