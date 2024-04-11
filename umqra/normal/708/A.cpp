#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	string str;
	cin >> str;
	bool allA = true;
	for (char c : str)
		if (c != 'a')
			allA = false;
	if (allA)
	{
		str.back() = 'z';
		printf("%s\n", str.c_str());
		return 0;
	}
	int l = 0;
	while (str[l] == 'a')
		l++;
	int r = l;
	while (r < (int)str.length() && str[r] != 'a')
		r++;
	for (int i = l; i < r; i++)
		str[i]--;
	printf("%s\n", str.c_str());
	
	return 0;
}