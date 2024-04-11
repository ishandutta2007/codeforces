#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
map<int,int> has;
int b[200013], c[200013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		has[x]+=1;
	}
	scanf("%d",&m);
	pair<int,int> best;
	int which = 1;
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=m;i++) scanf("%d",&c[i]);
	for (int i=1;i<=m;i++) {
		auto cur = MP(has[b[i]],has[c[i]]);
		if (cur>best) {
			best = cur;
			which = i;
		}
	}
	printf("%d\n",which);

	return 0;
}