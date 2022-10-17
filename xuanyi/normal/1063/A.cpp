#include <cstdio>
#include <algorithm>
using namespace std;

template <typename T>
inline void read(T &x){
	int ch, fl = 0;
	while (ch = getchar(), ch < 48 || 57 < ch) fl ^= ! (ch ^ 45); x = (ch & 15);
	while (ch = getchar(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}

template <typename T>
inline void print(T x){
	if (x < 0) x = -x, putchar('-');
	if (x > 9) print(x/10);
	putchar(x % 10 + 48);
}

const int MAXN = 100005;

int n;
char s[MAXN];

int main(){
	read(n);
	scanf("%s", s);
	sort(s, s+n);
	puts(s);
	return 0;
}