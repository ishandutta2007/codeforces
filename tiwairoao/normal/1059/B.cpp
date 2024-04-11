#include<cstdio>
const int MAXN = 1000;
char g[MAXN + 5][MAXN + 5];
bool vis[MAXN + 5][MAXN + 5];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", g[i]);
	for(int i=1;i<n-1;i++)
		for(int j=1;j<m-1;j++) {
			if( g[i-1][j] == '#'
				&& g[i-1][j+1] == '#'
				&& g[i-1][j-1] == '#'
				&& g[i][j+1] == '#'
				&& g[i][j-1] == '#'
				&& g[i+1][j+1] == '#'
				&& g[i+1][j] == '#'
				&& g[i+1][j-1] == '#' )
				vis[i-1][j-1] = 
				vis[i-1][j] =
				vis[i-1][j+1] =
				vis[i][j-1] =
				vis[i][j+1] =
				vis[i+1][j-1] =
				vis[i+1][j] =
				vis[i+1][j+1] = true;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if( g[i][j] == '#' && (!vis[i][j]) ) {
				puts("NO");
				return 0;
			}
	puts("YES");
}