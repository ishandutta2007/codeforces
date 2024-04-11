#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 51123987;

int m;

char w[2000010];
int d[2000001][2];
int start[2000001], finish[2000001], qa[2000001], qb[2000001];
long long sstart[2000001];

int good (int i) {
	return d[(i + 1) >> 1][i & 1] == ((i + 1) >> 1);
}

int main() {
	int n;
	scanf ("%d\n", &n);
        gets (w);
        long long all = 0;
        for (int t = 0; t < 2; t++) {
        	int l = 0, r = -1, j;
        	for (int i = 0; i < n; i++) {
        		if (i > r) j = 1; else j = min (d[l + r - i + t][t], r - i + t) + 1;
        		while (i + j - t < n && i - j >= 0 && w[i + j - t] == w[i - j]) j++;
        		j--;
        		d[i][t] = j;
        		if (i + j + t > r) { l = i - j; r = i + j - t; }
        		int x = i - d[i][t];
        		int y = i - t + d[i][t];
        		if (x <= y) {
        			all += d[i][t] + (1 - t);
        			qa[x]++;
        			if (i - t + 1 < n) qa[i - t + 1]--;
        			if (i > 0) qb[i - 1]--;
        			qb[y]++;
        		}
        	}
        }
        long long all2 = all - 1;
        if (all % 2 == 0) all /= 2; else all2 /= 2;
        all = (all % mod) * (all2 % mod);
        all %= mod;
        int cur = 0;
        for (int i = 0; i < n; i++) {
        	cur += qa[i];
        	start[i] = cur;
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
        	cur += qb[i];
        	finish[i] = cur;
        }
        long long sum = 0;
        for (int i = 0; i + 1 < n; i++) {
        	sum += finish[i];
        	all = (all - (sum * start [i + 1]) % mod + mod) % mod;
        }
        printf ("%d\n", (int)(all % mod));
	return 0;
}