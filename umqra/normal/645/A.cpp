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

string scan()
{
	string a, b;
	cin >> a >> b;
	reverse(b.begin(), b.end());
	string res = a + b;
	for (int i = 0; i < 4; i++)
	{
		if (res[i] == 'X')
		{
			res.erase(res.begin() + i);
			break;
		}
	}
	return res;
}

int main()
{
	string a = scan();
	string b = scan();
	for (int i = 0; i < 3; i++)
	{
		if (a == b)
		{
			puts("YES");
			return 0;
		}
		rotate(a.begin(), a.begin() + 1, a.end());
	}
	puts("NO");
	return 0;
}