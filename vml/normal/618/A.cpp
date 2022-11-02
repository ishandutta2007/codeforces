#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <memory.h>

#define ll long long
#define ld double
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

int main() {
	int n;

	cin >> n;

	vector <int> v;

	for (int i = 0; i < n; i++) {
		v.push_back(1);

		while (v.size() > 1 && v.back() == v[(int)v.size() - 2]) {
			v.pop_back();
			v.back()++;
		}
	}

	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << ' ';
	}

	return 0;
}