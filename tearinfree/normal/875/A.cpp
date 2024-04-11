#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	
	vector<int> ans;
	for(int i=max(1,n-100);i<n;i++) {
		int val=i,sum=i;
		while(val) {
			sum+=val%10; val/=10;
		}
		if(sum==n) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
	return 0;
}