#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
int x[3], y[3], p[3];
int w[3], h[3]; char l[3];
void test() {
	int i, j, k;
	if(w[1] == w[0]) {
		if(w[2] == w[1] && w[0] == h[0] + h[1] + h[2]) {
			printf("%d\n", w[0]);
			for(k = 0; k < 3; k++)
				for(i = 0; i < h[k]; i++) {
					for(j = 0; j < w[k]; j++)
						putchar(l[k]);
					putchar('\n');
				}
			exit(0);
		}
		if(h[2] == h[0] + h[1] && h[2] == w[0] + w[2]) {
			printf("%d\n", h[2]);
			for(i = 0; i < h[2]; i++) {
				for(j = 0; j < h[2]; j++)
					if(j >= w[0]) putchar(l[2]);
					else if(i < h[0]) putchar(l[0]);
					else putchar(l[1]);
				putchar('\n');
			}
			exit(0);
		}
	} else if(w[1] > w[0]) {
		if(w[0] + w[2] == w[1] && h[0] == h[2] && w[1] == h[0] + h[1]) {
			printf("%d\n", w[1]);
			for(i = 0; i < w[1]; i++) {
				for(j = 0; j < w[1]; j++)
					if(i >= h[0]) putchar(l[1]);
					else if(j < w[0]) putchar(l[0]);
					else putchar(l[2]);
				putchar('\n');
			}
			exit(0);
		}
	} else {
		if(w[1] + w[2] == w[0] && h[1] == h[2] && w[0] == h[0] + h[1]) {
			printf("%d\n", w[0]);
			for(i = 0; i < w[0]; i++) {
				for(j = 0; j < w[0]; j++)
					if(i < h[0]) putchar(l[0]);
					else if(j < w[1]) putchar(l[1]);
					else putchar(l[2]);
				putchar('\n');
			}
			exit(0);
		}
	}
}

int main() {
	int i, j;
	for(i = 0; i < 3; i++) {
		scanf("%d %d", &x[i], &y[i]);
		p[i] = i;
	}
	do {
		for(i = 0; i < 8; i++) {
			for(j = 0; j < 3; j++) {
				w[j] = x[p[j]]; h[j] = y[p[j]];
				l[j] = "ABC"[p[j]];
				if(i & (1 << j))
					swap(w[j], h[j]);
			}
			test();
		}
	} while(next_permutation(p, p + 3));
	puts("-1");	
}