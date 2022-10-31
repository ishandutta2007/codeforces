#include <bits/stdc++.h>
using namespace std;

int n;
int on = 0;
bool has[20][1013];
int res[20][1013];

void setup() {
	for (int i=1;i<n;i*=2) {
		for (int j=1;j<=n;j+=2*i) {
			for (int k=j;k<j+i;k++) {
				has[on][k] = 1;
			}
		}
		for (int j=1;j<=n;j++) {
			has[on+1][j] = !has[on][j];
		}
		on+=2;
	}
}

int main() {
	scanf("%d",&n);
	setup();
	for (int i=0;i<on;i++) {
        vector<int> cur;
        for (int j=1;j<=n;j++) {
			if (has[i][j]) {
				cur.push_back(j);
			}
        }
        printf("%d\n",cur.size());
        for (int j: cur) printf("%d ",j);
        printf("\n");
        fflush(stdout);
        for (int j=1;j<=n;j++) scanf("%d",&res[i][j]);
	}
	printf("-1\n");
	for (int i=1;i<=n;i++) {
		int val = 1.1e9;
        for (int j=0;j<on;j++) {
			if (!has[j][i]) {
				val = min(val,res[j][i]);
			}
        }
		printf("%d ",val);
	}
	printf("\n");
	fflush(stdout);

	return 0;
}