#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;
const int MOD = 1e9+7;

int inv(int x) {
	int p = MOD-2;
	int ans = 1;
	for (int i=0;i<30;i++) {
		if (p&(1<<i)) ans = ((ll) ans*x)%MOD;
		x = ((ll) x*x)%MOD;
	}
	return ans;
}

int prime[1000013];
vector<int> locs[1000013];
int on[1000013];

int n,q;
int a[200013];
vector<int> has[200013];
vector<pair<int,int> > need[200013];

int ans[200013];

int ft[200013];
void update(int i, int v) { while (i<=n) ft[i] = ((ll) ft[i]*v)%MOD, i+=i&(-i); }
int query(int i) {
	int res = 1;
	while (i>0) {
		res = ((ll) res*ft[i])%MOD;
		i-=i&(-i);
	}
	return res;
}

int main() {
	for (int i=0;i<1000013;i++) prime[i] = i;
	prime[0] = prime[1] = 0;
	for (int i=2;i<1000013;i++) if (prime[i]==i) {
		for (int j=i+i;j<1000013;j+=i) prime[j] = prime[i];
	}
	scanf("%d",&n);
	fill(ft,ft+n+1,1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) {
		update(i,a[i]);
		int cur = a[i];
		while (cur>1) {
			int p = prime[cur];
			while (cur%p==0) cur/=p;
			if (locs[p].size()==0) {
				update(i,inv(p));
				update(i,p-1);
			}
			locs[p].push_back(i);
			has[i].push_back(p);
		}
	}
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int l,r;
		scanf("%d%d",&l,&r);
		need[l].push_back(MP(r,i));
	}
	for (int i=1;i<=n;i++) {
		for (auto qq: need[i]) {
			ans[qq.B] = ((ll) query(qq.A)*inv(query(i-1)))%MOD;
		}
		for (int p: has[i]) {
			on[p]+=1;
			if (on[p]<locs[p].size()) {
				update(locs[p][on[p]],inv(p));
				update(locs[p][on[p]],p-1);
			}
		}
	}
	for (int i=0;i<q;i++) printf("%d\n",ans[i]);

	return 0;
}