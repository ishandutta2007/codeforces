#include <bits/stdc++.h>

char s[10][10]; int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%s", s[i] + 1);
	
	int x = 1, y = 1, t = 0;
	while( true ) {
		int px = n + 5, py = m + 5;
		for(int i=x;i<=n;i++) for(int j=y;j<=m;j++) if( s[i][j] == '*' ) {
			if( (px + py > i + j) || (px + py == i + j && i < px) )
				px = i, py = j;
		}
		if( px > n ) break;
		t++, s[x = px][y = py] = '.';
	}
	printf("%d\n", t);
}