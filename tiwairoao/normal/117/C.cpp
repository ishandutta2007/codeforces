#include<cstdio>
const int MAXN = 5000;
int A[MAXN + 5][MAXN + 5], n;
char str[MAXN + 5];
int nxt[MAXN + 5];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%s", str + 1);
		for(int j=1;j<=n;j++)
			A[i][j] = str[j] - '0';
	}
	int hd = 1, tl = 1; nxt[1] = -1;
	for(int i=2;i<=n;i++) {
		nxt[i] = -1;
		if( A[i][hd] ) {
			int p = nxt[hd];
			while( p != -1 ) {
				if( A[p][i] ) {
					printf("%d %d %d\n", p, i, hd);
					return 0;
				}
				p = nxt[p];
			}
			nxt[i] = hd, hd = i;
		}
		else if( A[tl][i] ) {
			int p = hd;
			while( p != tl ) {
				if( A[i][p] ) {
					printf("%d %d %d\n", i, p, tl);
					return 0;
				}
				p = nxt[p];
			}
			nxt[tl] = i, tl = i;
		}
		else {
			int p = hd;
			while( true ) {
				if( A[p][i] && A[i][nxt[p]] )
					break;
				p = nxt[p];
			}
			int q = hd;
			while( q != p ) {
				if( A[i][q] ) {
					printf("%d %d %d\n", i, q, p);
					return 0;
				}
				q = nxt[q];
			}
			q = nxt[nxt[p]];
			while( q != -1 ) {
				if( A[q][i] ) {
					printf("%d %d %d\n", q, i, nxt[p]);
					return 0;
				}
				q = nxt[q];
			}
			nxt[i] = nxt[p], nxt[p] = i;
		}
	}
	puts("-1");
}