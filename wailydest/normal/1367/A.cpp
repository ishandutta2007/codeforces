#include <cstdio>
using namespace std;

int main() 
{
	char s[101];
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int i;
		for (i = 0; s[i]; i += 2) printf("%c", s[i]);
		printf("%c\n", s[i - 1]);
	}
	return 0;
}