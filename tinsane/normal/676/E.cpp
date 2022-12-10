#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:167772160000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional>
#include <climits>
#include <cstring>
typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
//typedef std::pair<long double,long double> pdd;
#define forn(N)          for(int i = 0; i<(int)N; i++)
#define fornj(N)         for(int j = 0; j<(int)N; j++)
#define fornk(N)         for(int k = 0; k<(int)N; k++)
#define forn1(N)          for(int i = 1; i<=(int)N; i++)
#define fornj1(N)         for(int j = 1; j<=(int)N; j++)
#define fornk1(N)         for(int k = 1; k<=(int)N; k++)
#define PI 3.1415926535897932384626433
#define v vector
#define ll long long
#define print(n) printf("%d ", (n));
#define printll(n) printf("%I64d", (n));
#define printline() printf("\n");
#define read(n) scanf("%d", &n);
#define read2(n, m) scanf("%d%d", &n, &m);
#define readll(n) scanf("%I64d", &n);
#define mp make_pair
using namespace std;


int coef[110000];
bool known[110000];

int main()
{
#if defined(_DEBUG) || defined(_RELEASE)
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//(File".in", "r", stdin); freopen(File".out", "w", stdout);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	bool nK = 0;
	int n, k; cin >> n >> k;
	forn(n + 1) {
		string s; cin >> s;
		if (s == "?") {
			nK = 1;
			known[i] = 0;

		}
		else {
			int j = 0;
			if (s[0] == '-')j++;
			known[i] = 1;
			coef[i] = 0;
			while (j < s.length()) {
				coef[i] *= 10;
				coef[i] += (s[j] - '0');
				j++;
			}
			if (s[0] == '-')coef[i] = -coef[i];

		}


	}
	if (nK && k != 0) {
		if (n % 2 == 1)cout << "Yes";
		else cout << "No";
		return 0;


	}
	if (k == 0) {
		if (known[0]) {
			if (coef[0] == 0)cout << "Yes";
			else cout << "No";
			return 0;
		}
		int kn = 0;
		forn(n + 1)if (known[i])kn++;
		if (kn % 2 == 1)cout << "Yes";
		else cout << "No";
		return 0;

	}
	int now = 0;
	forn(n + 1) {
		now = now + coef[i] * k;
		if (now % k != 0) {
			cout << "No";
			return 0;
		}
		now /= k;

	}
	if (now == 0)cout << "Yes";
	else cout << "No";

	return 0;

}