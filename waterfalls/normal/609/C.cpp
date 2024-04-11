#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> has;

int main() {
	scanf("%d",&n);
	has.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&has[i]);
	int tot = accumulate(has.begin(),has.end(),0);
	sort(has.begin(),has.end());
	int low = tot/n;
	int high = tot/n+1;
	int num = n-tot%n;
	int ans = 0;
	for (int i=0;i<num;i++) ans+=abs(has[i]-low);
	for (int i=num;i<n;i++) ans+=abs(has[i]-high);
	printf("%d\n",ans/2);

	return 0;
}