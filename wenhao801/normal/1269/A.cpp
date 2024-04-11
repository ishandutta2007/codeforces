#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000001;
bool isprime[MAXN] = {};
int prime[MAXN] = {};
int cnt = 0;

inline int read () {
    char c = getchar();
    int ret = 0, t = 1;
    while (c < '0' || c > '9') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    int n = read();
    int i, j;
    for (i = 2; i <= 10000000; i++) {
        if (isprime[i]) prime[++cnt] = i;
        for (j = 1; j <= cnt && i * prime[j] < 10000000; j++)
            isprime[i * prime[j]] = false;
    }
	for (i = 4; i <= 1000000000; i++) {
		if (!isprime[i] && !isprime[i + n]) {
			printf("%d %d\n", i + n, i);
			break;
		}
	}
    return 0;
}