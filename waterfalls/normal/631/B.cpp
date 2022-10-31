#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int rowc[5013], rowt[5013];
int colc[5013], colt[5013];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++) {
		int type,r,c;
		scanf("%d%d%d",&type,&r,&c);
		if (type==1) {
			rowc[r] = c;
			rowt[r] = i;
		} else {
			colc[r] = c;
			colt[r] = i;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (rowt[i]>colt[j]) printf("%d ",rowc[i]);
			else printf("%d ",colc[j]);
		}
		printf("\n");
	}

    return 0;
}