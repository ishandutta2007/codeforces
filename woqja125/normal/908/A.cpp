#include<cstdio>
using namespace std;
int main() {
	int ans = 0;
	char in[100];
	scanf("%s", in);
	for (int i = 0; in[i]; i++) {
		if (in[i] >= '0' && in[i] <= '9') {
			if ((in[i] - '0') % 2 == 1) ans++;
		}
		else if (in[i] == 'a' || in[i] == 'e' || in[i] == 'o' || in[i] == 'u' || in[i] == 'i') ans++;
	}
	printf("%d\n", ans);
	return 0;
}