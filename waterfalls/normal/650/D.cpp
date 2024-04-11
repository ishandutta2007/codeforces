#include <bits/stdc++.h>
using namespace std;

int n,m;
int h[400013];
int l[400013], r[400013];
int lis, in[400013];

int x[400013], v[400013];
int nl[400013], nr[400013];
vector<int> need[400013];

void invert() {
	reverse(h+1,h+n+1);
	for (int i=1;i<=n;i++) h[i] = 1e9+7-h[i];
	swap(l,r);
	reverse(l+1,l+n+1);
	reverse(r+1,r+n+1);
	reverse(in+1,in+n+1);
	for (int i=1;i<=m;i++) v[i] = 1e9+7-v[i];
	swap(nl,nr);
	reverse(need+1,need+n+1);
}
void process() {
	vector<int> best(n+1,1.1e9);
	best[0] = 0;
	for (int i=1;i<=n;i++) {
		for (int j: need[i]) {
			nl[j] = lower_bound(best.begin(),best.end(),v[j])-best.begin();
		}
		l[i] = lower_bound(best.begin(),best.end(),h[i])-best.begin();
		best[l[i]] = h[i];
	}
	lis = *max_element(l+1,l+n+1);
	int val = 1.1e9;
	int on = lis;
	for (int i=n;i>=1;i--) {
		if (l[i]==on && h[i]<val) {
			in[i]+=1;
			val = h[i];
			on-=1;
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&x[i],&v[i]);
		need[x[i]].push_back(i);
	}
	for (int r=0;r<2;r++) {
		invert();
		process();
	}
	for (int i=1;i<=m;i++) {
		int ans = nl[i]+nr[i]-1;
		if (in[x[i]]==2) ans = max(ans,lis-1);
		else ans = max(ans,lis);
		printf("%d\n",ans);
	}

	return 0;
}