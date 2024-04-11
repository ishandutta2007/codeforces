#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 50005, L = 55;

int n;

int ord[N];

int len[N];

char s[N][L];

bool mycmp(int i, int j) {
	for (int k = 0; k < len[i] + len[j]; ++k) {
		char chi = k < len[i] ? s[i][k] : s[j][k - len[i]],
		     chj = k < len[j] ? s[j][k] : s[i][k - len[j]];
		if (chi < chj) {
			return true;
		} else if (chi > chj) {
			return false;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		len[i] = strlen(s[i]);
		ord[i] = i;
	}
	sort(ord, ord + n, mycmp);
	for (int i = 0; i < n; ++i) {
		printf("%s", s[ord[i]]);
	}
	printf("\n");
	return 0;
}