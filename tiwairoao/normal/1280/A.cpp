#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAXN = 1000000;
const int MOD = int(1E9) + 7;

char s[MAXN + 5];
int n, x, ans;

void solve() {
	scanf("%d%s", &x, s + 1);
	n = strlen(s + 1), ans = n;
	for(int i=1;i<=x;i++) {
		int p = s[i] - '0';
		ans = (ans + 1LL*(p-1)*(ans-i)%MOD) % MOD;
		if( n < x ) {
			int m = n;
			for(int q=1;q<p;q++) {
				for(int j=i+1;j<=m;j++) {
					if( n < x )
						s[++n] = s[j];
					else break;
				}
				if( n >= x ) break;
			}
		}
	}
	printf("%d\n", (ans + MOD) % MOD);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}