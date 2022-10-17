#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		char s[200000];
		scanf("%d%s", &n, s);
		int inc = 0;
		for (int i = 0; i < n - 1; ++i) if (s[i] == '<') ++inc;
		int down = n - inc, up = n;
		printf("%d ", down--);
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == '>') printf("%d ", down--);
			else {
				int amount = 1;
				for (int j = i + 1; j < n - 1 && s[j] == '<'; ++j, ++amount);
				for (int i = amount - 1; i >= 0; --i) printf("%d ", up - i);
				up -= amount;
				i += amount - 1;
			}
		}
		printf("\n");
		down = n - inc;
		up = down + 1;
		printf("%d ", down--);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '>') printf("%d ", down--);
			if (s[i] == '<') printf("%d ", up++);
		}
		printf("\n");
	}
	return 0;
}