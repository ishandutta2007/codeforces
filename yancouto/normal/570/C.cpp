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

char str[300009];
int main() {
	int m, i, x; char c;
	scanf("%*d %d %s", &m, str + 1);
	int ct = 0;
	for(i = 1; str[i]; i++)
		if(str[i] == '.' && str[i - 1] == '.')
			ct++;
	for(i = 0; i < m; i++) {
		scanf("%d %c", &x, &c);
		if(c == '.') {
			if(str[x] != '.') {
				if(str[x-1] == '.') ct++;
				if(str[x+1] == '.') ct++;
			}
		} else {
			if(str[x] == '.') {
				if(str[x-1] == '.') ct--;
				if(str[x+1] == '.') ct--;
			}
		}
		str[x] = c;
		printf("%d\n", ct);
	}
	return 0;
}