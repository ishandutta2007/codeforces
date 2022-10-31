#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n = 1000,m;
int ans = 0;
int deg[2][1013];
pair<int,int> has[2][1013][1013];
int color[100013];

int c[2];
void dfs(int x, int p) {
	auto i = has[p][x][c[!p]];
	if (has[!p][i.A][c[p]].B) dfs(i.A,!p);
	else has[!p][i.A][c[!p]] = MP(0,0);
	has[p][x][c[p]] = i;
	has[!p][i.A][c[p]] = MP(x,i.B);
	color[i.B] = c[p];
}

int main() {
	scanf("%*d%*d%d",&m);
	for (int i=1;i<=m;i++) {
		int x[2];
		scanf("%d%d",&x[0],&x[1]);
		for (int d=0;d<2;d++) {
			deg[d][x[d]]+=1;
			ans = max(ans,deg[d][x[d]]);
			for (c[d]=1;has[d][x[d]][c[d]].B;c[d]++);
		}
		if (c[0]!=c[1]) dfs(x[1],1);
		for (int d=0;d<2;d++) has[d][x[d]][c[0]] = MP(x[!d],i);
		color[i] = c[0];
	}
	printf("%d\n",ans);
	for (int i=1;i<=m;i++) printf("%d ",color[i]);
	printf("\n");

	return 0;
}