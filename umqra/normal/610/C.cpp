#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
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

vector <vector<int>> solve(int k)
{
	if (k == 0)
	{
		return {{1}};
	}
	vector <vector<int>> t = solve(k - 1);
	for (int i = 0; i < (int)t.size(); i++)
	{
		vector <int> s = t[i];
		t[i].insert(t[i].end(), s.begin(), s.end());
	}
	int sz = (int)t.size();
	for (int i = 0; i < sz; i++)
	{
		t.push_back({});
		for (int s = 0; s < sz; s++)
			t.back().push_back(t[i][s]);
		for (int s = sz; s < 2 * sz; s++)
			t.back().push_back(-t[i][s]);
	}
	return t;
}

int main()
{
	int k;
	scanf("%d", &k);
	vector <vector<int>> res = solve(k);
	for (int i = 0; i < (int)res.size(); i++)
	{
		for (int x : res[i])
			putchar(x == 1 ? '+' : '*');
		puts("");
	}
	return 0;
}