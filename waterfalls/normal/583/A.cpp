#include <bits/stdc++.h>
using namespace std;

int n;
int has[113];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n*n;i++) {
		int h,v;
		scanf("%d%d",&h,&v);
		if (!has[h] && !has[v+n]) {
			printf("%d\n",i+1);
			has[h] = has[v+n] = 1;
		}
	}

	return 0;
}