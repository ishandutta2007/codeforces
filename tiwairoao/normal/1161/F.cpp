#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 50;
bool cmp(int x, int y, bool t) {
	if( !t ) return x > y;
	else return x < y;
}
// x  y ? 
int a[MAXN + 5][MAXN + 5], n;
bool tg[MAXN + 5][MAXN + 5];
int lnk[2*MAXN + 5];
void get_match(bool t) {
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			tg[i][j] = false;
	for(int i=1;i<=2*n;i++)
		lnk[i] = 0;
	while( true ) {
		bool flag = true;
		for(int i=1;i<=n;i++)
			if( !lnk[i] ) {
				int mx = 0;
				for(int j=1;j<=n;j++)
					if( !tg[i][j] && (mx == 0 || cmp(a[i][j], a[i][mx], t)) )
						mx = j;
				if( !lnk[mx+n] )
					lnk[i] = mx + n, lnk[mx+n] = i;
				else if( cmp(a[i][mx], a[lnk[mx+n]][mx], !t) ) {
					int x = lnk[mx+n];
					lnk[i] = mx + n, lnk[mx+n] = i;
					tg[x][mx] = true, lnk[x] = 0;
				}
				else tg[i][mx] = true;
				flag = false;
			}
		if( flag ) break;
	}
}
/*
 
0 : 
1 : 
*/ 
void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &a[i][j]);
	puts("B"), fflush(stdout);
	char str[5] = {}; int x;
	scanf("%s%d", str, &x);
	get_match( (str[0] == 'I') == (x <= n) );
	while( true ) {
		printf("%d\n", lnk[x]), fflush(stdout);
		int op;
		scanf("%d", &op);
		if( op == -1 ) return ;
		else if( op == -2 ) exit(0);
		else x = op;
	}
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}