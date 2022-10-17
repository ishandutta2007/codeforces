#include <cstdio>
#include <algorithm>

const int N = 100000;
int t;
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		int amt[2] = {0, 0};
		scanf("%s", s);
		for (int i = 0; s[i];) {
			++amt[s[i] - '0'];
			do {
				++i;
			} while (s[i] && s[i] == s[i - 1]);
		}
		printf("%d\n", std::min(2, amt[0]));
	}
	return 0;
}