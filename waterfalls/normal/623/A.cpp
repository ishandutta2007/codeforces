#include <bits/stdc++.h>
using namespace std;

int n,m;
int adj[513][513];
char c[513];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a][b] = adj[b][a] = 1;
	}
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
		if (!adj[i][j]) {
			if (c[i]) c[j] = 'a'+'c'-c[i];
			else if (c[j]) c[i] = 'a'+'c'-c[j];
			else c[i] = 'a', c[j] = 'c';
		}
	}
	for (int i=1;i<=n;i++) if (!c[i]) c[i] = 'b';
	bool ok = 1;
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
		if (adj[i][j]!=(abs(c[i]-c[j])<=1)) ok = 0;
	}
	if (!ok) printf("No\n");
	else {
		printf("Yes\n");
		printf("%s\n",c+1);
	}

	return 0;
}