#include <bits/stdc++.h>
using namespace std;

int n,q;
int ans[1000013];
int num[2];

int main() {
	scanf("%d%d",&n,&q);
	n/=2;
	bool flip = 0;
	int offset = 0;
	while (q--) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			int x;
			scanf("%d",&x);
			if (x<0) x = (x+4*n)%(2*n);
			if (x%2==1) {
				num[flip]+=1;
				flip^=1;
				x-=1;
			}
			offset = (offset+x/2)%n;
		} else flip^=1;
	}
	for (int i=0;i<n;i++) {
		if (!flip) {
			ans[2*((i+offset+num[1])%n)] = 2*i;
			ans[2*((i+offset+num[0])%n)+1] = 2*i+1;
		} else {
			ans[2*((i+offset+num[0])%n)] = 2*i+1;
			ans[2*((i+offset+num[1])%n)+1] = 2*i;
		}
	}
	for (int i=0;i<2*n;i++) printf("%d ",ans[i]+1);
	printf("\n");

	return 0;
}