#include <bits/stdc++.h>
using namespace std;

int n,m;
bool on[113];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		for (int j=0;j<x;j++) {
			int y;
			scanf("%d",&y);
			on[y] = 1;
		}
	}
	printf("%s\n",*min_element(on+1,on+m+1)==1 ? "YES" : "NO");

	return 0;
}