#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[205];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), cnt = 0;
	for (int i = 1; i <= n; ++i) {
	  if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
		  s[i] = s[i + 1] = s[i + 2] = '\0';
		}
	}
	for (int i = 1; i <= n; ++i) {
  	if (s[i] != '\0') {
			++cnt;
			putchar(s[i]);
		} else if (cnt && s[i] == '\0' && s[i + 1] != '\0') putchar(' ');
	}	
	printf("\n");
	return 0;
}