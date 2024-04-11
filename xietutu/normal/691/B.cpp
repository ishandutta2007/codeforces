#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 1005;
char s[maxn];
int n;
bool flag;
bool is(char ch) {
	if (ch == 'A' || ch == 'H' || ch == 'I' || ch == 'M' || ch == 'O' || ch == 'o' ||
		ch == 'T' || ch == 'U' || ch == 'V' || ch == 'v' || ch == 'W' || ch == 'w' ||
		ch == 'X' || ch == 'x' || ch == 'Y') 
		return true;
	return false;
}
bool equal(char a, char b) {
	if (a == 'b' && b == 'd') return true;
	if (a == 'p' && b == 'q') return true;
	if (a == 'd' && b == 'b') return true;
	if (a == 'q' && b == 'p') return true;
	return false;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	flag = true;
	for (int i = 1; i <= n / 2; ++i)
		if (s[i] == s[n - i + 1]) {
			if (!is(s[i])) flag = false;
		}
		else if (!equal(s[i], s[n - i + 1])) flag = false;
	if (n % 2 == 1 && !is(s[n / 2 + 1])) flag = false;
	if (flag) printf("TAK\n");
	else printf("NIE\n");
}