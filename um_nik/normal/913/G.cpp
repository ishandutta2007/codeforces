#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int L = 40;
const int M = 30;

struct Num {
	int a[L];

	Num() {
		for (int i = 0; i < L; i++)
			a[i] = 0;
	}
	Num(int x) {
		for (int i = 0; i < L; i++)
			a[i] = 0;
		int len = 0;
		while(x > 0) {
			a[len++] = x % 10;
			x /= 10;
		}
	}

	Num operator + (const Num &A) const {
		Num R = Num();
		for (int i = 0; i < L; i++)
			R.a[i] = a[i] + A.a[i];
		for (int i = 0; i < L - 1; i++) {
			R.a[i + 1] += R.a[i] / 10;
			R.a[i] %= 10;
		}
		R.a[L - 1] %= 10;
		return R;
	}
	Num operator * (const Num &A) const {
		Num R = Num();
		for (int i = 0; i < L; i++)
			R.a[i] = 0;
		for (int i = 0; i < L; i++)
			for (int j = 0; i + j < L; j++)
				R.a[i + j] += a[i] * A.a[j];
		for (int i = 0; i < L - 1; i++) {
			R.a[i + 1] += R.a[i] / 10;
			R.a[i] %= 10;
		}
		R.a[L - 1] %= 10;
		return R;
	}

	void print() {
		int m = L - 1;
		while(a[m] == 0) m--;
		for (int i = m; i >= 0; i--)
			printf("%d", a[i]);
		printf("\n");
	}
};

char s[L];
int a[L];

Num P200;
Num P1;

void solve() {
	scanf("%s", s);
	Num ANS = Num(200);
	int len = strlen(s);
	for (int i = 0; i < M; i++)
		a[i] = 0;
	for (int i = 0; i < len; i++)
		a[M - 1 - i] = (int)(s[i] - '0');
	ll X = 0;
	for (int i = M - 1; i >= 0; i--) {
		X *= 10;
		X &= (1LL << M) - 1;
		X += a[i];
		X &= (1LL << M) - 1;
	}
	X = (1LL << M) - X;
	if (X % 10 == 0) X += 1LL << M;
	for (int i = 0; i < M - 12; i++) {
		a[i] = X % 10;
		X /= 10;
	}
	Num PER = Num(2);
	Num PERLEN = Num(1);
	Num CUR = P200;
	for (int k = 0; k < M; k++) {
		//cerr << "!!!!!  " << k << endl;
		while(a[k] != CUR.a[k]) {
			ANS = ANS + PERLEN;
			CUR = CUR * PER;
		//	CUR.print();
		}
		Num NEWPERLEN = PERLEN;
		Num NEWPER = PER;
		Num NXT = CUR * PER;
		while(CUR.a[k] != NXT.a[k]) {
			NXT = NXT * PER;
			NEWPER = NEWPER * PER;
			NEWPERLEN = NEWPERLEN + PERLEN;
		}
		PER = NEWPER;
		PERLEN = NEWPERLEN;
	}
	//cerr << "here" << endl;
	ANS.print();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	P1 = Num(2);
	P200 = Num(1);
	for (int i = 0; i < 200; i++)
		P200 = P200 * P1;
/*
	Num P10 = Num(1);
	for (int i = 0; i < 10; i++)
		P10 = P10 * P1;
	P10.print();
	return 0;
*/
	int t;
	scanf("%d", &t);
	while(t--) {
//		cerr << t << endl;
		solve();
	}

	return 0;
}