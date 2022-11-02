#include <cstdio>

int main() {
	char s[2][100004];
	scanf(" %s %s", s[0], s[1]);
	bool up = true;
	for(int i = 0; s[0][i]; i++)
		if(s[0][i] != s[1][i]) {
			s[0][i] = s[up][i];
			up = !up;
		}
	if(up) printf("%s", s[0]);
	else puts("impossible");
}