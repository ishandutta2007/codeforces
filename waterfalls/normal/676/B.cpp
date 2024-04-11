#include <bits/stdc++.h>
using namespace std;

int n,t;
int has[13][13];

const int MAGIC = 1<<13;

int main() {
	scanf("%d%d",&n,&t);
	while (t--) {
		has[1][1]+=MAGIC;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=i;j++) {
				if (has[i][j]>MAGIC) {
					has[i+1][j]+=(has[i][j]-MAGIC)>>1;
					has[i+1][j+1]+=(has[i][j]-MAGIC)>>1;
					has[i][j] = MAGIC;
				}
			}
		}
	}
	int ans = 0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++) ans+=has[i][j]==MAGIC;
	}
	printf("%d\n",ans);

	return 0;
}