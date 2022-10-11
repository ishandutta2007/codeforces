#include <cstdio>

const int ms = 2020;


char str[ms][ms];
int freq[ms];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf(" %s", str[i]);
		for(int j = 0; j < m; j++) {
			if(str[i][j] == '1') {
				freq[j]++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		bool valid = true;
		for(int j = 0; j < m; j++) {
			if(str[i][j] == '1' && freq[j] == 1) {
				valid = false;
				break;
			}
		}
		if(valid) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}