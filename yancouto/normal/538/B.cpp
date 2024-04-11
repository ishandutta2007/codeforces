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
char all[1000000];
int j = 0;
void cch(char c) {
	all[j++] = c;
}
int main() {
	scanf("%s", str);
	int num = 0;
	while(atoi(str)) {
		num++;
		bool left = false;
		for(int i = 0; str[i]; i++) {
			if(str[i] != '0') { left = true; cch('1'); str[i]--; }
			else if(left) cch('0');
		}
		cch(' ');
	}
	cch('\0');
	printf("%d\n%s\n", num, all);
}