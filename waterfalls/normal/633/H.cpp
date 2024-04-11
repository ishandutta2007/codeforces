#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,m,q;
int f[30013];
pair<int,int> a[30013];
int b[30013];

int main() {
	scanf("%d%d",&n,&m);
	f[1] = f[2] = 1%m;
	for (int i=3;i<30013;i++) {
		f[i] = (f[i-1]+f[i-2])%m;
	}
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i].A);
		a[i].B = i+1;
	}
	sort(a,a+n);
	for (int i=0;i<n;i++) b[i] = a[i].A%m;
	scanf("%d",&q);
	while (q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		int on = 1;
		ll ans = 0;
		int prev = -1;
		for (int i=0;i<n;i++) {
			if (l<=a[i].B && a[i].B<=r) {
				if (a[i].A>prev) {
					ans = ans+b[i]*f[on++];
					prev = a[i].A;
				}
			}
		}
		printf("%lld\n",ans%m);
	}

    return 0;
}