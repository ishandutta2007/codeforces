#include <bits/stdc++.h>
using namespace std;

int n,m;
int val[113][4];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		val[i][0] = 2*i+1;
		val[i][3] = 2*i+2;
		val[i][1] = val[i][0]+2*n;
		val[i][2] = val[i][3]+2*n;
	}
	for (int i=0;i<n;i++) {
		if (val[i][1]<=m) printf("%d ",val[i][1]);
		if (val[i][0]<=m) printf("%d ",val[i][0]);
		if (val[i][2]<=m) printf("%d ",val[i][2]);
		if (val[i][3]<=m) printf("%d ",val[i][3]);
	}
	printf("\n");

	return 0;
}