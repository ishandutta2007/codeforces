#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

int main() {
	scanf("%d",&n);
	int prev;
	scanf("%d",&prev);
	ans.push_back(prev);
	for (int i=1;i<n;i++) {
		int x;
		scanf("%d",&x);
		if (__gcd(prev,x)!=1) ans.push_back(1);
		ans.push_back(x);
		prev = x;
	}
	printf("%d\n",ans.size()-n);
	for (int i: ans) printf("%d ",i);
	printf("\n");

	return 0;
}