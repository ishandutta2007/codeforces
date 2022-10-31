#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Ant {
	int p,i;
	bool operator<(Ant o) const { return p<o.p; }
};

int n,m;
ll t;
vector<Ant> l,r,all,after;
int ans[300013];

int main() {
	scanf("%d%d%lld",&n,&m,&t);
	for (int i=0;i<n;i++) {
		int p;
		char d;
		scanf("%d %c",&p,&d);
		int diff = (d=='L') ? -1 : 1;
		if (diff==-1) l.push_back({ p-1,i });
		else r.push_back({ p-1,i });
		all.push_back({ p-1,i });
		after.push_back({ (p-1+(t%m)*diff+m)%m,i });
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	sort(all.begin(),all.end());
	sort(after.begin(),after.end());
	ll num = t/m+2;
	ll left = 0;
	for (Ant a: l) {
		ll cur = (t-a.p-1+m)/m;
		left+=num+cur;
	}
	for (Ant a: r) {
		ll cur = num-(t+a.p)/m;
		left+=cur;
	}
	left%=n;
	for (int i=0;i<n;i++) {
		int j = all[(left+i)%n].i;
		ans[j] = after[i].p+1;
	}
	for (int i=0;i<n;i++) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}