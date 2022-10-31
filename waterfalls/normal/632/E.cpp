#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> cost;
int change[1000013];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		cost.push_back(a);
	}
	sort(cost.begin(),cost.end());
	cost.erase(unique(cost.begin(),cost.end()),cost.end());
	change[k*cost[0]] = k+1;
	for (int i=1;i<=k*cost.back();i++) if (change[i]>1) {
		for (int j: cost) {
			change[i+j-cost[0]] = max(change[i+j-cost[0]],change[i]-1);
		}
	}
	for (int i=1;i<=k*cost.back();i++) if (change[i]) printf("%d ",i);
	printf("\n");

	return 0;
}