#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> has;

int main() {
	scanf("%d%d",&n,&m);
	has.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&has[i]);
	sort(has.begin(),has.end(),greater<int>());
	int on = 0;
	while (m>0) m-=has[on++];
	printf("%d\n",on);

	return 0;
}