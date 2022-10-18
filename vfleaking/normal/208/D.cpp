#include <iostream>
#include <cstdio>
using namespace std;

typedef long long Int64;

const int MaxN = 50;

int main()
{
	int n;
	int p[MaxN + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	int a, b, c, d, e;
	Int64 nA = 0ll, nB = 0ll, nC = 0ll, nD = 0ll, nE = 0ll;
	cin >> a >> b >> c >> d >> e;
	int rest = 0;
	for (int i = 1; i <= n; i++)
	{
		rest += p[i];
		nE += rest / e, rest %= e;
		nD += rest / d, rest %= d;
		nC += rest / c, rest %= c;
		nB += rest / b, rest %= b;
		nA += rest / a, rest %= a;
	}
	cout << nA << ' ' << nB << ' ' << nC << ' ' << nD << ' ' << nE << endl;
	cout << rest << endl;

	return 0;
}