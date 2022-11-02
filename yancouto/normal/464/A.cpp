#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

char str[1009]; int n, p;
void imp() {
	puts("NO");
	exit(0);
}
void ok(char *s) {
	printf("%s\n", s);
	exit(0);
}
bool okc(int i, char c) {
	if(i > 0 && str[i-1] == c) return false;
	if(i > 1 && str[i-2] == c) return false;
	return true;
}

int solve(int i, bool ok) {
	if(i < 0) return false;
	if(ok) {
		solve(i - 1, true);
		putchar(str[i]);
		return true;
	}
	for(char j = str[i] + 1; j < p + 'a'; j++)
		if(okc(i, j)) {
			solve(i - 1, true);
			putchar(j);
			str[i] = j;
			return true;
		}
	if(!solve(i - 1, false)) return false;
	for(char j = 'a'; j <= 'z'; j++)
		if(okc(i, j)) {
			putchar(j);
			str[i] = j;
			return true;
		}
}

int main() {
	scanf("%d %d %s", &n, &p, str);	
	if(p == 1) imp();
	if(p == 2) {
		if(n == 1 && str[0] == 'b') imp();
		if(n == 1) ok("b");
		if(str[0] == 'a') ok("ba");
		imp();
	}
	if(solve(n - 1, false)) putchar('\n');
	else puts("NO");
}