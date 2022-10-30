#include <bits/stdc++.h>
using namespace std;

const int MAGIC = 80;
typedef long double ld;

int q;
int on = 2;
int p[500013];
ld prod[500013][MAGIC];

int main() {
	for (int i=0;i<500013;i++) fill(prod[i],prod[i]+MAGIC,1);
	scanf("%d",&q);
	while (q--) {
		int type, v;
		scanf("%d%d",&type,&v);
		if (type==1) {
			p[on] = v;
			on+=1;
			vector<int> has;
			for (int r=0;r<MAGIC-1;r++) {
				has.push_back(v);
				v = p[v];
			}
			for (int i=MAGIC-2;i>=0;i--) {
				int x = has[i];
				prod[p[x]][i+1]/=(0.5+prod[x][i]/2);
			}
			prod[has[0]][0]/=2;
			for (int i=0;i<MAGIC-1;i++) {
				int x = has[i];
				prod[p[x]][i+1]*=(0.5+prod[x][i]/2);
			}
        } else {
			ld ans = 0;
			for (int i=1;i<MAGIC;i++) {
				ans+=i*(prod[v][i]-prod[v][i-1]);
			}
			printf("%1.9f\n",(double) ans);
		}
	}

	return 0;
}