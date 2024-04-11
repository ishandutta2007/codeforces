/*
	Team: Dandelion
	Room: 258
*/

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

int main()
{
	string str;
	int n;
	cin >> n;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < (int)str.length(); i++)
	{
		int dx = 0;
		int dy = 0;
		for (int s = i; s < (int)str.length(); s++)
		{
			if (str[s] == 'U')
				dx++;
			if (str[s] == 'D')
				dx--;
			if (str[s] == 'L')
				dy++;
			if (str[s] == 'R')
				dy--;
			if (dx == 0 && dy == 0)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}