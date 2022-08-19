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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200;
string a[N];
int n;
string b[N];
map<string, string> mapchik;

string BIB_START = "\\begin{thebibliography}{99}";
string BIB_END = "\\end{thebibliography}";

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s;
	while(true) {
		cin >> s;
		if (s == BIB_START) break;
		if (s[0] != '\\') continue;
		int p = 0;
		while(s[p] != '{') p++;
		int q = p + 1;
		while(s[q] != '}') q++;
		a[n++] = s.substr(p + 1, q - p - 1);
	}
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int p = 0;
		while(s[p] != '{') p++;
		int q = p + 1;
		while(s[q] != '}') q++;
		b[i] = s.substr(p + 1, q - p - 1);
		mapchik[b[i]] = s.substr(q + 1, (int)s.length() - q - 1);
	}
	bool ok = true;
	for (int i = 0; i < n; i++)
		ok &= a[i] == b[i];
	if (ok) {
		cout << "Correct" << endl;
		return 0;
	}
	cout << "Incorrect" << endl;
	cout << BIB_START << endl;
	for (int i = 0; i < n; i++)
		cout << "\\bibitem{" << a[i] << "}" << mapchik[a[i]] << endl;
	cout << BIB_END << endl;


	return 0;
}