#include <bits/stdc++.h>
using namespace std;

int n;
int p[1013][1013];
bool done[1013];
double ans[1013];
double tot[1013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&p[i][j]);
	for (int i=0;i<n;i++) {
		ans[i] = 1/0.;
		tot[i] = 1;
	}
	ans[n-1] = 0;
	for (int r=0;r<n;r++) {
		int i = -1;
		for (int j=0;j<n;j++) if (!done[j] && (i==-1 || ans[j]<ans[i])) i = j;
		done[i] = 1;
		for (int j=0;j<n;j++) if (!done[j] && p[j][i]) {
			ans[j] = (ans[j]==1/0.) ? 1 : ans[j]*(1-tot[j]);
			ans[j]+=tot[j]*p[j][i]/100.*ans[i];
			tot[j]*=(1-p[j][i]/100.);
			ans[j]/=(1-tot[j]);
		}
	}
	printf("%1.9f\n",ans[0]);

	return 0;
}