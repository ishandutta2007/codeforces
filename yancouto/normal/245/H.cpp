#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 5010;

int pdPal[MAX][MAX], pdCnt[MAX][MAX], len;
char str[MAX];

int pal(int i, int j) {
	if(i >= j) return 1;
	int &ret = pdPal[i][j];
	if(ret != -1) return ret;
	if(str[i] == str[j]) return ret = pal(i + 1, j - 1);
	else return ret = 0;
}

int cnt(int i, int j) {
	if(i > j) return 0;
	int &ret = pdCnt[i][j];
	if(ret != -1) return ret;
	ret = cnt(i + 1, j) + cnt(i, j - 1) - cnt(i + 1, j - 1);
	if(pal(i, j)) ret++;
	return ret;
}

int main() {
	scanf(" %s", str);
	len = strlen(str);
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			pdPal[i][j] = pdCnt[i][j] = -1;
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", cnt(--a, --b));
	}
	return 0;
}