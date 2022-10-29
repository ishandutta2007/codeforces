#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
char s[10];
bool flag;
int main() {
	scanf("%d%d", &n, &m);
	flag = true;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%s", s);
			if (s[0] == 'C' || s[0] == 'M' || s[0] == 'Y') flag = false;
		}	
	if (flag) printf("#Black&White\n");
	else printf("#Color\n");	
}