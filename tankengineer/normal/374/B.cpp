#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000;
char s[N];

int main() {
	scanf("%s", s);
	int l = strlen(s);
	long long ans = 1;
	for (int i = 0; i + 1 < l; ++i) {
		if (s[i] - '0' + s[i + 1] - '0' != 9) {
			continue;
		}
		int j = i + 1;
		while (j + 1 < l && s[j] - '0' + s[j + 1] - '0' == 9) {
			++j;
		}
		if ((j - i + 1) % 2) {
			ans *= (j - i + 2) / 2;
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}