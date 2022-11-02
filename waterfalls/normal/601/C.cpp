#include <bits/stdc++.h>
using namespace std;

#define prev prev_
#define next next_

typedef long double ld;

int n,m;
ld prev[100013], next[100013];
ld sums[100013];

int main() {
	scanf("%d%d",&n,&m);
	prev[0] = 1;
	for (int i=0;i<100013;i++) sums[i] = 1;
	int tot = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		x-=1;
		tot+=x;
		for (int j=0;j<=n*(m-1);j++) {
			next[j] = sums[j];
			if (j>=m) next[j]-=sums[j-m];
			if (j-x>=0) next[j]-=prev[j-x];
			next[j]/=(m-1);
		}
		for (int j=0;j<=n*(m-1);j++) prev[j] = next[j];
		sums[0] = prev[0];
		for (int j=1;j<=n*(m-1);j++) sums[j] = sums[j-1]+prev[j];
	}
	ld ans = 0;
	for (int j=0;j<tot;j++) ans+=prev[j];
	ans*=(m-1);
	printf("%1.12f\n",(double) ans+1);

	return 0;
}