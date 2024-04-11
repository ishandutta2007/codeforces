#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const char Letters[4] = {'A', 'G', 'C', 'T'};
const int N = (int)2e5 + 100;
const int K = 19;
const int pow2 = (1 << K);
const double pi = atan(1.) * 4;


char S[pow2], T[pow2];
int a[pow2], b[pow2];
complex <double> ptA[pow2], ptB[pow2];
complex <double> root[pow2];
int bitPos[pow2];

void expandLetters(int k, int len)
{
	int prevDist = k + 1;
	for (int i = 0; i < len; i++)
	{
		prevDist++;
		if (a[i] == 1)
			prevDist = 0;
		if (prevDist <= k)
			a[i] = 1;
	}
}

void precalc()
{
	bitPos[0] = 0;
	int maxPow = -1;
	for (int i = 1; i < pow2; i++)
	{
		if ((i & (i - 1)) == 0)
			maxPow++;
		bitPos[i] = bitPos[i ^ (1 << maxPow)];
		bitPos[i] ^= (1 << (K - maxPow - 1));
	}
	for (int i = 0; i < pow2; i++)
	{
		double alpha = 2 * pi * i / pow2;
		root[i] = complex<double>(cos(alpha), sin(alpha));
	}	
}

complex<double> tmp[pow2];
bool coolPos[pow2];

void fft(complex<double> *pa)
{
	for (int i = 0; i < pow2; i++)
		tmp[i] = pa[bitPos[i]];
	for (int i = 0; i < pow2; i++)
		pa[i] = tmp[i];

	for (int len = 1; 2 * len <= pow2; len *= 2)
	{
		for (int pos = 0; pos + 2 * len <= pow2; pos += 2 * len)
		{
			int index = 0;
			int m = pow2 / len / 2;
			for (int it = pos; it < pos + len; it++)
			{
				auto cur = root[index * m];
				tmp[it] = pa[pos + index] + cur * pa[pos + index + len];
				tmp[it + len] = pa[pos + index] - cur * pa[pos + index + len];
				index++;
			}
		}
		for (int i = 0; i < pow2; i++)
			pa[i] = tmp[i];
	}
}

void solve(char l, int lenS, int lenT, int k)
{
	for (int i = 0; i < lenT; i++)
		b[i] = (T[i] == l ? 1 : 0);

	for (int i = 0; i < lenS; i++)
		a[i] = (S[i] == l ? 1 : 0);
	expandLetters(k, lenS);
	reverse(a, a + lenS);
	expandLetters(k, lenS);
	reverse(a, a + lenS);

	int sum = 0;
	for (int i = 0; i < lenT; i++)
		sum += b[i];
	reverse(b, b + lenT);

	for (int i = 0; i < pow2; i++)
	{
		ptA[i] = a[i];
		ptB[i] = b[i];
	}
	fft(ptA);
	fft(ptB);
	for (int i = 0; i < pow2; i++)
		ptA[i] *= ptB[i];
	fft(ptA);
	for (int i = 0; i < pow2; i++)
		ptA[i] /= pow2;
	reverse(ptA + 1, ptA + pow2);
	for (int i = 0; i < lenS - lenT + 1; i++)
	{
		int value = (int)(ptA[i + lenT - 1].real() + 0.5);
		if (value != sum)
			coolPos[i] = false;
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	precalc();


	eprintf("Precalc - END\n");
	int lenS, lenT, k;
	scanf("%d%d%d", &lenS, &lenT, &k);
	if (lenS < lenT)
	{
		puts("0");
		return 0;
	}

	scanf(" %s %s", S, T);

	fill(coolPos, coolPos + pow2, true);
	for (int i = 0; i < 4; i++)
	{
		char letter = Letters[i];
		solve(letter, lenS, lenT, k);
	}
	int cnt = 0;
	for (int i = 0; i < lenS - lenT + 1; i++)
		if (coolPos[i])
			cnt++;

	printf("%d", cnt);
	return 0;
}