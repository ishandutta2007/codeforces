#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	char s[105];
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		int j = i;
		while (s[j + 1] == s[j]) ++j;
		if (j - i + 1 >= 7) {
			printf("YES\n");
			return 0;
		}
		i = j;
	}
	printf("NO\n");
	return 0;
}