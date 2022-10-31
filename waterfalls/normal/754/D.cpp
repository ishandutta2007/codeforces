#include <bits/stdc++.h>
using namespace std;

struct Coupon {
	int l,r,i;
	bool operator<(Coupon o) { return l<o.l; }
};

int n,k;
Coupon coupons[300013];
priority_queue<int> rs;

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&coupons[i].l,&coupons[i].r);
		coupons[i].i = i;
	}
	sort(coupons+1,coupons+n+1);
	int best = -1;
	int which = 0;
	for (int i=1;i<=n;i++) {
        rs.push(-coupons[i].r);
        while (rs.size()>k) rs.pop();
		if (rs.size()==k && -rs.top()-coupons[i].l>best) {
			best = -rs.top()-coupons[i].l;
			which = coupons[i].l;
		}
	}
	printf("%d\n",best+1);
	int has = 0;
	for (int i=1;i<=n;i++) {
		if (best==-1 || (coupons[i].l<=which && which+best<=coupons[i].r)) {
			if (has<k) {
				has+=1;
				printf("%d ",coupons[i].i);
			}
		}
	}
	printf("\n");

	return 0;
}