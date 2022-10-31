#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a,b;
int x[1000013];

ll cost[1000013];
ll kadane(int s, int e, int d, bool w) {
	ll ans = 0;
	ll cur = 0;
	for (int i=s;i!=e+d;i+=d) {
		cur+=cost[i];
		if (w) cur = min(cur,0LL);
		ans = min(ans,cur);
	}
	return ans;
}
ll solve(int p) {
	ll res = 0;
	int first = n+1;
	int last = 0;
	for (int i=1;i<=n;i++) {
		if (x[i]%p==0) cost[i] = a;
		else if (x[i]%p==1 || x[i]%p==p-1) {
			cost[i] = a-b;
			res+=b;
		} else {
			first = min(first,i);
			last = max(last,i);
		}
	}
	if (last) {
		for (int i=first;i<=last;i++) {
			if (x[i]%p==1 || x[i]%p==p-1) res-=b;
		}
		return res+kadane(first-1,1,-1,0)+kadane(last+1,n,+1,0)+(ll) a*(last-first+1);
	}
	else return res+kadane(1,n,1,1);
}

ll go(int v) {
	ll res = 1e18;
	for (int i=2;i*i<=v;i++) {
		if (v%i==0) {
			res = min(res,solve(i));
			while (v%i==0) v/=i;
		}
	}
	if (v>1) res = min(res,solve(v));
	return res;
}

int main() {
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	ll ans = 1e18;
	for (int d=-1;d<=1;d++) ans = min(ans,go(x[1]+d));
	for (int d=-1;d<=1;d++) ans = min(ans,go(x[n]+d));
	printf("%lld\n",ans);

	return 0;
}