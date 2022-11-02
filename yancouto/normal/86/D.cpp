#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int M = 200009;

int n, t;
int l, r;
int a[M], inv[M], cnt[M];
unsigned long long current_total;
unordered_map<int, int> ks;

inline void rem(int i) {
	// printf("ks[a[%d]] = %d\n", i, ks[a[i]]);
	current_total += -2 * cnt[a[i]]-- * inv[a[i]] + inv[a[i]];
	// printf("ks[a[%d]] = %d after\n", i, ks[a[i]]);
}

inline void add(int i) {
	// printf("ks[a[%d]] = %d\n", i, ks[a[i]]);
	current_total += 2 * cnt[a[i]]++ * inv[a[i]] + inv[a[i]];
	// printf("ks[a[%d]] = %d after\n", i, ks[a[i]]);
}

inline void right_l() {
	// printf("total before right_l %I64u\n", current_total);
	rem(l++);
	// printf("total after right_l %I64u\n", current_total);
}
inline void left_l() {
	// printf("total before left_l %I64u\n", current_total);
	add(--l);
	// printf("total after left_l %I64u\n", current_total);
}
inline void right_r() {
	// printf("total before right_r %I64u\n", current_total);
	add(++r);
	// printf("total after right_r %I64u\n", current_total);
}
inline void left_r() {
	// printf("total before left_r %I64u\n", current_total);
	rem(r--);
	// printf("total after left_r %I64u\n", current_total);
}


int ql[M], qr[M];
int q[M];
int sq_n;
unsigned long long resp[M];
bool cmp_block(int i, int j) {
	return ((int)(ql[i] / sq_n)) < ((int)(ql[j] / sq_n));
}
bool cmp_r(int i, int j) {
	return qr[i] < qr[j];
}


int main() {
	int i;
	scanf("%d %d", &n, &t);
	int aux = 1;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int &aa = ks[a[i]];
		if(!aa) {
			aa = aux++;
			inv[aa] = a[i];
		} 
		a[i] = aa;
	}
	for(sq_n = 0; sq_n * sq_n <= n; sq_n++);
	sq_n--;
	r = -1; l = current_total = 0; 
	for(i = 0; i < t; i++) {
		scanf("%d %d", &ql[i], &qr[i]);
		q[i] = i; ql[i]--; qr[i]--;
	} 
	sort(q, q + t, cmp_r);
	stable_sort(q, q + t, cmp_block); 
	for(i = 0; i < t; i++) {
		while(l < ql[q[i]]) right_l();
		while(l > ql[q[i]]) left_l();
		while(r < qr[q[i]]) right_r();
		while(r > qr[q[i]]) left_r();
		// printf("query (%d, %d)\n", ql[q[i]], qr[q[i]]);
		resp[q[i]] = current_total; 
	}
	for(i = 0; i < t; i++)
		printf("%I64u\n", resp[i]);
	return 0;
}