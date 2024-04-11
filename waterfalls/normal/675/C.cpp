#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map<ll,int> has;

int main() {
	scanf("%d",&n);
	ll cur = 0;
	int ans = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		cur+=x;
		has[cur]+=1;
		ans = max(ans,has[cur]);
	}
	printf("%d\n",n-ans);

	return 0;
}