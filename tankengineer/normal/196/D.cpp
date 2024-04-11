#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 4 * 100005;
int d, rev;
char s[N];

const int MUL = 37, MOD = 1000000007;
int h[N], rh[N][2], powMul[N];

int hash(const int l, const int len) {
	return ((h[l + len] - (long long)h[l] * powMul[len]) % MOD + MOD) % MOD;
}

void insert(const int i) {
	for (int delta = 0; delta < 2; ++delta) {
		int len = (d + delta) / 2;
		long long tmp = (long long)rh[i][delta];
		if (i >= len) {
			(tmp -= (s[i - len] - 'a' + 1)) %= MOD;
		}
		rh[i + 1][delta] = (tmp * rev % MOD + (long long)(s[i] - 'a' + 1) * powMul[len - 1] % MOD) % MOD;
	}
}

bool pali(const int st, const int delta) {
	if (st < 0) {
		return false;
	}
	int r = (d + delta) / 2;
	return rh[st + r][delta] == hash(st + r + (d + delta) % 2, r);
}

bool check(const int i) {
	h[i + 1] = ((long long)h[i] * MUL + s[i] - 'a' + 1) % MOD;	
	return !pali(i - d + 1, 0) && !pali(i - d, 1);
}

long long inverse(const long long i) {
	return i == 1 ? 1 : (MOD - MOD / i) * inverse(MOD % i) % MOD;
}

bool plusone(int i, int &ret) {
	while (i > -1) {
		if (s[i] == 'z') {
			s[i] = 'a';
		} else {
			++s[i];
			break;
		}
		--i;
	}
	ret = i;
	return i > -1;
}
int main() {
	rev = inverse(MUL);
	powMul[0] = 1;
	for (int i = 1; i < N; ++i) {
		powMul[i] = (long long)powMul[i - 1] * MUL % MOD;
	}
	scanf("%d%s", &d, s);
	int l = strlen(s), tmp;
	if (!plusone(l - 1, tmp)) {
		puts("Impossible");
		return 0;
	}
	bool cmp = false;
	for (int i = 0; i < l; ++i) {
		bool succ = false;
		char old = s[i];
		for (char ch = cmp ? 'a' : s[i]; !succ && ch <= 'z'; ++ch) {
			s[i] = ch;
			succ |= check(i);	
		}
		while (!succ) {
			int tmp;
			if (!plusone(i, tmp)) {
				puts("Impossible");
				return 0;
			} else {
				i = tmp;
				succ |= check(i);
				cmp = true;
			}
		}
		insert(i);
		if (!cmp && s[i] != old) {
			cmp = true;
		}
	}
	printf("%s\n", s);
	return 0;
}