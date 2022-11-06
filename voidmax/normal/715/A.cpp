#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <long double, long double>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
//#define _CRT_DISABLE_PERFCRIT_LOCKS
using namespace std;

typedef long long base;

base n, m = 2;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin >> n;
	For(i, 1, n + 1) {
		base c = m / i;
		cout << (base)i * (i + 1) * (i + 1) - c << endl;
		m = (base)(i + 1) * i;
	}
}