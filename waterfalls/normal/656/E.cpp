#include <bits/stdc++.h>
using namespace std;

int n;
int adj[10][10];

void read2(int i, int j) {
	j==n ? 0 :
	(scanf("%d",&adj[i][j]),
	read2(i,j+1), 0);
}
void read(int i) {
	i==n ? 0 :
	(read2(i,0),
	read(i+1), 0);
}

void floyd3(int k, int i, int j) {
	j==n ? 0 :
	(adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]),
	floyd3(k,i,j+1), 0);
}
void floyd2(int k, int i) {
	i==n ? 0 :
	(floyd3(k,i,0),
	floyd2(k,i+1), 0);
}
void floyd(int k) {
	k==n ? 0 :
	(floyd2(k,0),
	floyd(k+1), 0);
}

int ans = 0;
void check2(int i, int j) {
	j==n ? 0 :
	(ans = max(ans,adj[i][j]),
	check2(i,j+1), 0);
}
void check(int i) {
	i==n ? 0 :
	(check2(i,0),
	check(i+1), 0);
}

int main() {
	scanf("%d",&n);
	read(0);
	floyd(0);
	check(0);
	printf("%d\n",ans);

	return 0;
}