#include <bits/stdc++.h>
using namespace std;

int n;
char s[100013];
int d[100013];
bool vis[100013];

bool dfs(int x) {
	if (x<0 || x>=n) return true;
	if (vis[x]) return false;
	vis[x] = 1;
	if (s[x]=='>') return dfs(x+d[x]);
	else return dfs(x-d[x]);
}

int main() {
	scanf("%d",&n);
	scanf(" %s",&s);
	for (int i=0;i<n;i++) scanf("%d",&d[i]);
	if (dfs(0)) printf("FINITE\n");
	else printf("INFINITE\n");

	return 0;
}