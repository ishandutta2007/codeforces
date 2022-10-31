#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> has;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		has.push_back(x);
	}
	if (*max_element(has.begin(),has.end())==0) return printf("0\n"), 0;
	while (has.back()==0) has.pop_back();
	while (has[0]==0) has.erase(has.begin());
	long long ans = 1;
	while (has.size()) {
		has.pop_back();
		int cur = 1;
		while (has.size() && has.back()==0) {
			cur+=1;
			has.pop_back();
		}
		ans*=cur;
	}
	printf("%lld\n",ans);

	return 0;
}