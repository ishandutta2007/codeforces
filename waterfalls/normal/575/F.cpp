#include <bits/stdc++.h>
using namespace std;

#define prev prev_
typedef long long ll;

int n,x;
int l[5013], r[5013];
vector<int> comp;
ll dp[10013];
ll prev[10013];

int cost(int i, int j) {
	if (i==0) return 0;
	if (comp[j]<l[i]) return l[i]-comp[j];
	if (comp[j]>r[i]) return comp[j]-r[i];
	return 0;
}

int main() {
	scanf("%d%d",&n,&x);
	comp.push_back(x);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&l[i],&r[i]);
		comp.push_back(l[i]);
		comp.push_back(r[i]);
	}
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for (int j=0;j<comp.size();j++) dp[j] = cost(n,j);
    swap(dp,prev);
    for (int i=n-1;i>=0;i--) {
		ll best = 1e18;
		for (int j=0;j<comp.size();j++) dp[j] = 1e18;
		for (int j=0;j<comp.size();j++) {
			if (j) best+=comp[j]-comp[j-1];
			best = min(best,prev[j]);
			dp[j] = min(dp[j],cost(i,j)+best);
		}
		best = 1e18;
		for (int j=comp.size()-1;j>=0;j--) {
			if (j<comp.size()-1) best+=comp[j+1]-comp[j];
			best = min(best,prev[j]);
			dp[j] = min(dp[j],cost(i,j)+best);
		}
		swap(dp,prev);
    }
    printf("%lld\n",prev[lower_bound(comp.begin(),comp.end(),x)-comp.begin()]);

	return 0;
}