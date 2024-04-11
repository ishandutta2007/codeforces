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
	// freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	int f0 = -1, f1 = -1, l0 = -1, l1 = -1;
	for (int i = 0; i + 1 < s.size(); i++) {
		if ((s[i] == 'A') && (s[i + 1] == 'B')) {
			l0 = i;
			if (f0 < 0) f0 = i + 1;
		}
		if ((s[i] == 'B') && (s[i + 1] == 'A')) {
			l1 = i;
			if (f1 < 0) f1 = i + 1;
		}
	}
	if ((f0 == -1) || (f1 == -1)) {
		puts("NO"); return 0;
	}
	if ((l1 > f0) || (l0 > f1)) {
		puts("YES"); return 0;
	}
	puts("NO");
}