#include <cstdio>
#ifndef ONLINE_JUDGE
#define debug(...) {fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__);}
#else
#define debug(...) //
#endif
#include <algorithm>
using namespace std;

#define mod(a) ((a) % m)
#include <cmath>

int usado[2000003];
int ti;
int until(long long m, long long h, long long a, long long x, long long y, int &to_A, int &loop_A) {
	int count = 0;
	while(true) {
		debug("h1:%d\n", h);
		if(usado[h] == ti) return -2;
		usado[h] = ti; 
		if(h == a) break;
		h = mod(mod(x * h) + y);
		count++;
	}
	to_A = count;
	ti++;
	count = 1;
	h = mod(mod(x * h) + y);
	while(true) {
		debug("h2:%d\n", h);
		if(usado[h] == ti) return -1;
		usado[h] = ti;
		if(h == a) break;
		h = mod(mod(x * h) + y);
		count++;
	}
	loop_A = count;
	return 0; // nao acontece
}

int main() {
	int m, h1, a1, x1, y1, h2, a2, x2, y2;
	scanf("%d %d %d %d %d %d %d %d %d", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);
	ti = 1;
	int t1, l1;
	int ret1 = until(m, h1, a1, x1, y1, t1, l1);
	ti++;
	int t2, l2;
	int ret2 = until(m, h2, a2, x2, y2, t2, l2);
	debug("ret1[%d] ret2[%d]\n", ret1, ret2);
	debug("t1[%d] l1[%d]\nt2[%d] l2[%d]\n", t1, l1, t2, l2);
	if(ret1 == -2 || ret2 == -2) { puts("-1"); return 0; }
	if(ret1 == -1 || ret2 == -1) {
		if(ret1 == -1 && ret2 == -1) printf("%d\n", (t1 == t2)? t1 : -1);
		if(ret1 == -1) { swap(t1, t2); swap(l1, l2); }
		printf("%d\n", ((t2 < t1) || ((t2 - t1) % l1))? -1 : t2);
		return 0;
	}
	ti++;
	long long s1 = t1, s2 = t2, b1 = l1, b2 = l2;
	if(s1 > s2) { swap(s1, s2); swap(b1, b2); }
	int swp = 1;
	while(true) {
		debug("s1[%I64d] s2[%I64d] b1[%I64d] b2[%I64d]\n", s1, s2, b1, b2);
		debug("dif[%I64d]\n", (s2 - s1) * swp);
		if(s1 == s2) { printf("%I64d\n", s1); return 0; }
		if(usado[(s2 - s1) * swp + 1000000] == ti) { puts("-1"); return 0; }
		usado[(s2 - s1) * swp + 1000000] = ti;
		long long m = (s2 - s1 + b1 - 1) / b1;
		s1 += b1 * m;
		swp = -swp;
		swap(s1, s2); swap(b1, b2);
	}
	return 0; // nao acontece
}