#include<cstdio>
#include<map>
using namespace std;
int M[26][5010][26];
int c[26];
char in[10000];
int main() {
	double re = 0;
	int n;
	scanf("%s", in);
	for (n = 0; in[n]; n++);
	for (int i = 0; i < n; i++) in[n + i] = in[i];
	for (int i = 0; i < n; i++) {
		c[in[i] - 'a']++;
		for (int j = 1; j < n; j++)  M[in[i] - 'a'][j][in[i + j] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (c[i] == 0) continue;
		int m = 0;
		for (int j = 0; j < n; j++) {
			int c = 0;
			for (int k = 0; k < 26; k++)
				if (M[i][j][k] == 1) c++;
			if (m < c) m = c;
		}
		re += m;
	}
	printf("%.10lf\n", re / n);
	return 0;
}