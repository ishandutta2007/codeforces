#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(1);
		while (((int)v.size() > 1) && (v[(int)v.size() - 1] == v[(int)v.size() - 2])) {
			int cur = v.back();
			v.pop_back();
			v.back() = cur + 1;
		}
	}
	for (int i = 0; i < (int)v.size(); i++) printf("%d ", v[i]);
	puts("");
}