#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#include <immintrin.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct pt {
	cat x, y;
};

cat vs(pt & A, pt & B, pt & O) {
	return (A.x-O.x) * (B.y-O.y) - (A.y-O.y) * (B.x-O.x);
}

cat ss(pt & A, pt & B, pt & O) {
	return (A.x-O.x) * (B.x-O.x) + (A.y-O.y) * (B.y-O.y);
}

using bset = uint64_t;

bool solve(const __restrict int32_t * v1, const __restrict int32_t * v2, const __restrict bset * b1, const __restrict bset * b2, int n, int32_t S) {
	const __m128i xs = _mm_set1_epi32(S);
	const __restrict __m128i * w1 = (const __m128i *) v1;
	const __restrict __m128i * w2 = (const __m128i *) v2;
	for(int k = 0; k < n/4+1; k += 16) {
		_mm_prefetch(v1+4*k+16, _MM_HINT_T0);
		_mm_prefetch(v1+4*k+32, _MM_HINT_T0);
		bset b = ((S&1) ? 0 : 0xFFFFFFFFFFFFFFFF) ^ b1[k/16] ^ b2[k/16];
		if(b == 0) {
			k += 15;
			continue;
		}
		_mm_prefetch(v1+4*k+48, _MM_HINT_T0);
		_mm_prefetch(v1+4*k+64, _MM_HINT_T0);
		for(int l = 0; l < 16; l++) {
			const __m128i sum = _mm_sub_epi32(w1[k+l], w2[k+l]);
			const __m128i cmp = _mm_cmpeq_epi32(sum, xs);
			if(!_mm_testz_si128(cmp, cmp)) return true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat S;
	cin >> N >> S;
	S *= 2;
	srand(S+7547);
	int C = rand()%N;
	vector<pt> V(N);
	for(int i = 0; i < N; i++) {
		cin >> V[i].x >> V[i].y;
		swap(V[i], V[rand()%(i+1)]);
	}
	int32_t area[2048][2048] __attribute__((aligned(64)));
	memset(area, 0, sizeof(area));
	cat A[2048][2048];
	bset odd[2048][2048/64];
	memset(odd, 0, sizeof(odd));
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) {
		if(i == j || i == C || j == C) continue;
		A[i][j] = vs(V[i], V[j], V[C]);
		A[j][i] = -A[i][j];
		if(abs(A[i][j]) == S) {
			cout << "Yes\n";
			cout << V[C].x << " " << V[C].y << "\n";
			cout << V[i].x << " " << V[i].y << "\n";
			cout << V[j].x << " " << V[j].y << "\n";
			return 0;
		}
		area[i][j] = A[i][j];
		area[j][i] = A[j][i];
		if(A[i][j]&1) {
			odd[i][j/64] |= 1ULL<<(j&63);
			odd[j][i/64] |= 1ULL<<(i&63);
		}
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) {
		if(!solve(area[j], area[i], odd[j], odd[i], i, S-A[i][j])) continue;
		for(int k = 0; k < i; k++) if(A[j][k]-A[i][k]+A[i][j] == S) {
			cout << "Yes\n";
			cout << V[i].x << " " << V[i].y << "\n";
			cout << V[j].x << " " << V[j].y << "\n";
			cout << V[k].x << " " << V[k].y << "\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}

// look at my code
// my code is amazing