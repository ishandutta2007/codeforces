#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int result() {
	char res[10]; scanf("%s", res);
	if( res[0] == 'W' ) exit(0);
	else return (res[0] == 'E' ? 0 : (res[0] == 'F' ? 1 : -1));
}

bool check(int x) {
	printf("? 1 1\n1\n%d\n", x), fflush(stdout);
	return (result() == -1);
}

bool check(int l, int r) {
	int c = r - l + 1; printf("? %d %d\n", c, c);
	for(int i=1;i<=c;i++) printf("%d%c", i, (i == c) ? '\n' : ' ');
	for(int i=1;i<=c;i++) printf("%d%c", l + i - 1, (i == c) ? '\n' : ' ');
	fflush(stdout); return (result() == 0);
}

void report(int x) {printf("! %d\n", x), fflush(stdout);}

int solve() {
	int n, k; scanf("%d%d", &n, &k);
	for(int i=1;i<=25;i++) {
		int p = rand() % (n - 1) + 2;
		if( check(p) ) return 1;
	}
	
	int s = 1;
	for(;(s << 1) <= n; s <<= 1) {
		if( !check(s + 1, s << 1) ) {
			int p = s + 1;
			for(s >>= 1; s; s >>= 1)
				if( check(p, p + s - 1) ) p += s;
			return p;
		}
	}
	
	int p = s + 1;
	for(; s; s >>= 1) {
		if( p + s - 1 <= n && check(p, p + s - 1) )
			p += s;
	}
	
	return p;
}

int main() {
	srand(20041112);
	int T; scanf("%d", &T);
	while( T-- ) report(solve());
}