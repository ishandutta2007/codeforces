#include <cstdio>

using namespace std;

int n;
char S[2000];
int a[2000];

int main() {
	scanf("%d", &n);
	scanf("%s", S + 1);
	for (int i = 1; i <= n; i++)
		a[i] = S[i] - '0';
	for (int i = 1; i < n; i++)
		if (a[i] == 1 && a[i + 1] == 1) {
			printf("No\n");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (a[i] == 0 && a[i - 1] == 0 && a[i + 1] == 0){
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
}