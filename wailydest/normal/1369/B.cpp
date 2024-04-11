#include <cstdio>
using namespace std;

const int N = 100000;
char s[N + 1];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d%s", &n, &s);
		int i = 0;
		while (i < n && s[i] == '0') ++i;
		int amt1 = i;
		i = n - 1;
		while (i >= 0 && s[i] == '1') --i;
		int amt2 = n - i - 1;
		if (amt1 + amt2 == n) printf("%s\n", s);
		else {
			for (int i = 0; i < amt1 + 1; ++i) printf("0");
			for (int i = 0; i < amt2; ++i) printf("1");
			printf("\n");
		}
	}
	return 0;
}