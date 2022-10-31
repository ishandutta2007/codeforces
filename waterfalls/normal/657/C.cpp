#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,by5,by1;
vector<int> t[5];
vector<int> special[5];

int l[5], r[5];
ll sum[5];

ll solve(int c) {
	for (int i=0;i<5;i++) {
		l[i] = r[i] = 0;
		sum[i] = 0;
	}
	ll res = 1e18;
	for (int j: special[c]) {
		for (int i=0;i<5;i++) {
			while (r[i]<t[i].size() && t[i][r[i]]<=j) {
				sum[i]+=t[i][r[i]++];
			}
		}
		while (accumulate(r,r+5,0)-accumulate(l,l+5,0)>k) {
			ll best = -1;
			int which = 0;
			for (int i=0;i<5;i++) {
				if (l[i]==r[i]) continue;
				ll cur = (ll) (j-t[i][l[i]])/5*by5+(ll) (j%5-t[i][l[i]]%5+15)%5*by1;
				if (cur>best) {
					best = cur;
					which = i;
				}
			}
			sum[which]-=t[which][l[which]++];
		}
		if (accumulate(r,r+5,0)-accumulate(l,l+5,0)==k) {
			ll cur = 0;
			for (int i=0;i<5;i++) {
				cur+=(ll) ((ll) (j-(j%5-i+10)%5)*(r[i]-l[i])-sum[i])/5*by5;
				cur+=(ll) (j%5-i+10)%5*(r[i]-l[i])*by1;
			}
			res = min(res,cur);
		}
	}
	return res;
}

int main() {
	scanf("%d%d%d%d",&n,&k,&by5,&by1);
	by5 = min(by5,5*by1);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		t[(x%5+5)%5].push_back(x);
		for (int d=0;d<5;d++) {
			special[(x%5+d+5)%5].push_back(x+d);
		}
	}
	for (int c=0;c<5;c++) sort(t[c].begin(),t[c].end());
	ll ans = 1e18;
	for (int c=0;c<5;c++) {
		sort(special[c].begin(),special[c].end());
		ans = min(ans,solve(c));
	}
	printf("%lld\n",ans);

	return 0;
}