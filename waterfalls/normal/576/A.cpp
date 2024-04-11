#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ans;

bool pp(int x) {
	int has = 0;
	for (int i=2;i<=1000;i++) {
		if (x%i==0) {
			if (has) return false;
			has = i;
			while (x%i==0) x/=i;
		}
	}
	if (has==0 || x==1) return true;
	return false;
}

void solve() {
	for (int i=2;i<=n;i++) if (pp(i)) ans.push_back(i);
}

int main() {
	scanf("%d",&n);
	solve();
	printf("%d\n",ans.size());
	for (int i: ans) printf("%d ",i);
	printf("\n");

	return 0;
}