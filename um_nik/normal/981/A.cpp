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

bool isPal(string s) {
	int L = (int)s.length();
	for (int i = 0; i < L; i++)
		if (s[i] != s[L - 1 - i])
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	if (!isPal(s)) {
		cout << s.length() << endl;
		return 0;
	}
	if (!isPal(s.substr(0, (int)s.length() - 1))) {
		cout << (int)s.length() - 1 << endl;
		return 0;
	}
	cout << 0 << endl;

	return 0;
}