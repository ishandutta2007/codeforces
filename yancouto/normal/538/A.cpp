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

char str[1000];
char *cf = "CODEFORCES";
int main() {
	scanf("%s", str);
	int i, j = 0, k;
	for(i = 0; cf[i] && str[i] && cf[i] == str[i]; i++);
	j = i; k = strlen(str); int g = strlen(cf);
	for(i = 0; (k+i-1) >= 0 && (g+i-1) >= 0 && str[k+i-1] == cf[g+i-1]; i--);
	if(j - i >= g) puts("YES");
	else puts("NO");
}