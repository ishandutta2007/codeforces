#include <bits/stdc++.h>
using namespace std;

int n;
int c[5013];
int has[5013];
int ans[5013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&c[i]);
	for (int i=0;i<n;i++) {
		int best = 0;
		memset(has,0,sizeof has);
		for (int j=i;j<n;j++) {
			has[c[j]]+=1;
			if (has[c[j]]>has[best] || (has[c[j]]==has[best] && c[j]<best)) {
				best = c[j];
			}
			ans[best]+=1;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}