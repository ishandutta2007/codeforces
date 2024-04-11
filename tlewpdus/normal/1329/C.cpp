#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int g, h, n, m;
ll arr[1050000];
ll ans[1050000];
int chk[1050000];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d%d", &h, &g);
		n = (1<<h)-1;
		for (int i=1;i<=n;i++) scanf("%lld",&arr[i]);
		for (int i=1;i<=n;i++) chk[i] = 0;
		m = (1<<g)-1;
		ll sum = 0;
		for (int i=m;i;i--) {
			int t = 1;
			if (i*2+1<=m) t = max(ans[i*2],ans[i*2+1])+1;
			int ti = i;
			for (int j=1;i*j<=n;j*=2) {
				for (int k=0;k<j;k++) {
					if (!chk[i*j+k]&&arr[i*j+k]>=t) {
						if (arr[ti]>arr[i*j+k]) {
							ti=i*j+k;
						}
					}
				}
			}
			chk[ti] = 1;
			sum += arr[ti];
			ans[i] = arr[ti];
		}
		printf("%lld\n",sum);
		for (int i=n;i;i--) {
			if (!chk[i]) printf("%d ",i);
		}
		puts("");
	}

	return 0;
}