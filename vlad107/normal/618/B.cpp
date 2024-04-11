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

const int N = 66;

int a[N][N], n, nom[N];

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
	for (int it = 0; it < n; it++) {	
		int x = -1;
		for (int i = 0; i < n; i++) {
			if (nom[i] != 0) continue;
			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (nom[j] != 0) continue;
				if (a[i][j] != it + 1) {
					flag = false;
					break;
				}
			}
			if (flag) {
				x = i;
				break;
			}
		}
		assert(x != -1);
		nom[x] = it + 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) assert(min(nom[i], nom[j]) == a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", nom[i]);
	puts("");
}