#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef int Hash;

const int N = 1000005;
int ibar, l, len[N];
char a[N], b[N];

const Hash MOD = 1000000007,
	  MUL = 157;
Hash reva[N], hasa[N], hasb[N], powMul[N];

inline void hasher(char *s, Hash h[]) {
	h[0] = 0;
	for (int i = 0; i < l; ++i) {
		h[i + 1] = ((long long)h[i] * MUL + s[i]) % MOD;
	}
}

inline int hash(const Hash h[], const int &l, const int &len) {
	return ((h[l + 1 + len] - (long long)h[l] * powMul[len + 1]) % MOD + MOD) % MOD;
}

int main() {
	gets(a);
	gets(b);
	int la = strlen(a), lb = strlen(b);
	if (la != lb) {
		printf("-1 -1\n");
		return 0;
	}
	l = la;
	powMul[0] = 1;
	for (int i = 0; i <= l; ++i) {
		powMul[i + 1] = (long long)powMul[i] * MUL % MOD;
	}
	ibar = -1;
	for (int i = 0; i < l - 1 && a[i] == b[l - i - 1]; ++i) {
		++ibar;
	}
	hasher(a, hasa);
	reverse(a, a + l);
	hasher(a, reva);
	hasher(b, hasb);
	for (int i = 0; i < l; ++i) {
		int left = -1, right = l - i - 1, mid;
		if (i) {
			left = max(len[i - 1] - i - 1, -1);
		}
		while (left < right) {
			mid = (left + right + 1) >> 1;
			if (hash(reva, 0, mid) == hash(hasb, i, mid)) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}
		len[i] = left + i + 1;
	}
	int ansx = -1, ansy = -1;
	for (int i = ibar; i >= 0 && ansx == -1; --i) {
		int left = -1, right = l - i - 1, mid;
		while (left < right) {
			mid = (left + right + 1) >> 1;
			if (hash(hasa, i + 1, mid) == hash(hasb, 0, mid)) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}
		if (len[left + 1] >= l - i - 1) {
			ansx = i;
			right = left + 1;
			left = 0;
			while (left < right) {
				mid = (left + right) >> 1;
				if (len[mid] >= l - i - 1) {
					right = mid;
				} else {
					left = mid + 1;
				}
			}
			ansy = ansx + left + 1;
		}
	}
	printf("%d %d\n", ansx, ansy);
	return 0;
}