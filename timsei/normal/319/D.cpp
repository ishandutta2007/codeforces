#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

unsigned long long Ba[N], Ba2[N], Pow[N];

const unsigned long long Base = 2333; 

char s[N], t[N];
int n;
int fucked, Sr, last, where;

unsigned long long get(int l, int r, bool cxt) {
	return (Ba[r] - Ba[l - 1] * Pow[r - l + 1]); 
}

unsigned long long get(int l, int r) {
	if(l > Sr)
	return get(l, r, 1);
	else {
		int n = last - 1;
		int La = Sr - l + 1;
		if(n - La < 0) return rand();
		unsigned long long A = (Ba2[n] - Ba2[n - La] * Pow[La]),
		B = (Ba[r] - Ba[Sr] * Pow[r - Sr]);
		int lB = r - Sr;
		return A * Pow[lB] + B;
	}
}

int Q[N], H[N];

int LCS(int x, int y) {
	int len = min(x, y), l = 0, r = len, res = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(get(x - mid + 1, x) == get(y - mid + 1, y)) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}

int LCP(int x, int y) {
	int len = min(n - x + 1, n  - y + 1), l = 0, r = len , res = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(get(x, x + mid - 1) == get(y, y + mid - 1)) {
			l = mid + 1;
			res = mid;
		}
		else r = mid - 1;
	}
	return res;
}

void rebuild(void) {
	Ba[n + 1] = 0;
	for(int i = 1; i <= n; ++ i) {
		Ba[i] = Ba[i - 1] * Base + s[i];
	}
}

bool vis[N];


main(void) {
	int T;
	for(T = 1; T --;) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		Pow[0] = 1;
		for(int i = 1; i <= n; ++ i) Pow[i] = Pow[i - 1] * Base;
		rebuild();
		
		for(int i = 1; i <= n / 2; ++ i) {
			last = 1, where = 0;
			fucked = 
			Sr = 0;
			for(int j = i; j <= n; j += i) {
				if(j - i) {
					Q[j] = LCS(j, j - i);
					Q[j] = min(Q[j], i);
					H[j] = LCP(j, j - i);
					if(Q[j] + H[j] - 1 >= i) {
						if(!fucked)
						for(int k = 1; k <= n; ++ k) vis[k] = 0;
						fucked = 1;
						int now = i + 1 - Q[j];
						int L = j - i - Q[j] + 1, R = j - i + now - 1;
						for(int k = L; k <= R; ++ k) vis[k] = 1;
						for(int k = last; k <= R; ++ k) {
							if(!vis[k]) {
								t[last] = s[k];
								Ba2[last] = Ba2[last - 1] * Base + t[last];
								++ last;
							}
						}
						Sr = R;
					}
				}
			}
			if(fucked) {
				int m = 0;
				for(int j = 1; j <= n; ++ j) if(!vis[j]) t[++ m] = s[j], Ba[m] = Ba[m - 1] * Base + t[m];
				n = m;
				for(int j = 1; j <= n; ++ j) s[j] = t[j];
			}
		}
		for(int i = 1; i <= n; ++ i) putchar(s[i]);
		puts("");
	}
}