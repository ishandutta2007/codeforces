#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[813][813];
int want[813];
int take[813];
int ans[813];

int main() {
	scanf("%d",&n);
	for (int i=1;i<2*n;i++) {
		for (int j=0;j<i;j++) scanf("%d",&a[i][j]), a[j][i] = a[i][j];
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<2*n;j++) if (!take[j]) {
			want[j] = -1;
			for (int k=0;k<2*n;k++) if (!take[k] && (want[j]==-1 || a[j][k]>a[j][want[j]])) want[j] = k;
		}
		for (int j=0;j<2*n;j++) if (!take[j] && want[want[j]]==j) {
			take[j] = take[want[j]] = 1;
			ans[j] = want[j];
			ans[want[j]] = j;
		}
	}
	for (int i=0;i<2*n;i++) printf("%d ",ans[i]+1);
	printf("\n");

	return 0;
}