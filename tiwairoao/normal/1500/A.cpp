#include <bits/stdc++.h>

const int N = 200000;
const int A = 2500000;

int a[N + 5], b[N + 5], n;

std::vector<int>v[A + 5];

int c[A*2 + 5], d[A*2 + 5];
int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &a[i]), v[a[i]].push_back(i);
	
	for(int i=1;i<=A;i++) if( v[i].size() >= 4 ) {
		puts("YES");
		printf("%d %d %d %d ", v[i][0], v[i][1], v[i][2], v[i][3]);
		return 0;
	}
	
	int p = -1;
	for(int i=1;i<=A;i++) if( v[i].size() >= 2 ) {
		if( p == -1 ) p = i;
		else {
			puts("YES");
			printf("%d %d %d %d ", v[p][0], v[i][0], v[p][1], v[i][1]);
			return 0;
		}
	}
	if( p != -1 ) c[p + p] = v[p][0], d[p + p] = v[p][1];
	
	int m = 0;
	for(int i=1;i<=A;i++) if( !v[i].empty() ) {
		b[++m] = v[i][0];
		for(int j=1;j<m;j++) {
			int x = a[b[j]] + i;
			if( c[x] ) {
				puts("YES");
				printf("%d %d %d %d ", c[x], d[x], b[j], v[i][0]);
				return 0;
			} else {
				c[x] = b[j], d[x] = v[i][0];
			}
		}
	}
	
	puts("NO");
}