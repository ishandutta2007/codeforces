#include <bits/stdc++.h>
using namespace std;

int m;
char s[10013];

int main() {
	scanf(" %s",s+1);
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		k%=(r-l+1);
		rotate(s+l,s+r+1-k,s+r+1);
	}
	printf("%s\n",s+1);

	return 0;
}