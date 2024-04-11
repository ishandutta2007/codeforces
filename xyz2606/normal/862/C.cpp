#include<bits/stdc++.h>
using namespace std;
const int N(100011);
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> ans;
	int tot(0);
	for(int i(1); i <= n - 2; i += 2) {
		ans.push_back(131072 + i);
		tot ^= ans.back();
		ans.push_back(131072 + i + 1);
		tot ^= ans.back();
	}
	if(ans.size() == n - 1)
		ans.push_back(tot ^ m);
	else {
		if((tot ^ m) == 0) {
			if(ans.size() == 0) {
				printf("NO\n");
				return 0;
			}else {
				ans.back() ^= 262144;
				tot ^= 262144;
			}
		}
		{
			ans.push_back(tot ^ m);
			ans.push_back(0);
		}
	}
	printf("YES\n");
	for(int i(0); i < n; i++) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
}