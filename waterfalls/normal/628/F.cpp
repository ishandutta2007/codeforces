#include <bits/stdc++.h>
using namespace std;

struct Hint {
	int up,cnt;
	bool operator<(Hint o) const { return up<o.up; }
};

int n,b,q;
Hint h[10013];
int has[10013][5], take[10013];

int main() {
	scanf("%d%d%d",&n,&b,&q);
	for (int i=1;i<=q;i++) {
		scanf("%d%d",&h[i].up,&h[i].cnt);
	}
	h[++q] = { b,n };
	sort(h,h+q+1);
	for (int i=1;i<=q;i++) {
		for (int j=h[i-1].up+1;j<=h[i].up;j++) has[i][j%5]+=1;
		take[i] = h[i].cnt-h[i-1].cnt;
		if (0>take[i] || take[i]>h[i].up-h[i-1].up) return printf("unfair\n"), 0;
	}
	for (int i=1;i<32;i++) {
		int need = n/5*__builtin_popcount(i);
		int can = 0;
		for (int k=1;k<=q;k++) {
			int cur = 0;
			for (int j=0;j<5;j++) if (i&(1<<j)) {
				cur+=has[k][j];
			}
			can+=min(cur,take[k]);
		}
		if (need>can) return printf("unfair\n"), 0;
	}
	printf("fair\n");

    return 0;
}