#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int transn(long long n) {
	int ret = 0, l = 0;
	while (n) {
		int d = n % 2;
		n /= 10;
		ret = ret | (d << l);
		++l;
	}
	return ret;
}

int transp(char *s) {
	int ret = 0;
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		int d = s[i] - '0';
		ret = (ret << 1) | d;
	}
	return ret;
}

int main() {
	int q;
	scanf("%d", &q);
	map<int, int> cnt;
	while (q--) {
		char op[2];
		scanf("%s", op);
		if (op[0] == '+' || op[0] == '-') {
			long long a;
			scanf("%I64d", &a);
			int b = transn(a);
			if (op[0] == '+') {
				++cnt[b];
			} else {
				--cnt[b];
			}
		} else if (op[0] == '?') {
			char s[19];
			scanf("%s", s);
			int b = transp(s);
			printf("%d\n", cnt[b]);
		}
	}
	return 0;
}