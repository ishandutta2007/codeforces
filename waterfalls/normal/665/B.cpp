#include <bits/stdc++.h>
using namespace std;

int n,m,k;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	vector<int> pos(k);
	for (int i=1;i<=k;i++) scanf("%d",&pos[i-1]);
	int ans = 0;
	for (int i=0;i<n*m;i++) {
		int x;
		scanf("%d",&x);
		auto ind = find(pos.begin(),pos.end(),x);
		ans+=ind-pos.begin()+1;
		pos.erase(ind);
		pos.insert(pos.begin(),x);
	}
	printf("%d\n",ans);

	return 0;
}