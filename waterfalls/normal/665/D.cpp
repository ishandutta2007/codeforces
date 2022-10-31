#include <bits/stdc++.h>
using namespace std;

bool prime[2000013];
void precalc() {
	fill(prime+2,prime+2000013,1);
	for (int i=2;i<2000013;i++) if (prime[i]) {
		for (int j=i+i;j<2000013;j+=i) prime[j] = 0;
	}
}

int n;
int a[1013];

int main() {
	precalc();
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int ans = 1;
	int cnt1 = count(a,a+n,1);
	for (int i=0;i<n;i++) {
		if (prime[a[i]+1]) {
			ans = max(ans,cnt1+1-(a[i]==1));
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (prime[a[i]+a[j]]) ans = max(ans,2);
		}
	}
	if (ans==1) return printf("1\n%d\n",a[0]), 0;
	for (int i=0;i<n;i++) {
		if (prime[a[i]+1] && ans==cnt1+1-(a[i]==1)) {
			printf("%d\n",ans);
			for (int j=0;j<cnt1-(a[i]==1);j++) printf("1 ");
			printf("%d\n",a[i]);
			return 0;
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (prime[a[i]+a[j]] && ans==2) {
				printf("%d\n%d %d\n",ans,a[i],a[j]);
				return 0;
			}
		}
	}

	return 0;
}