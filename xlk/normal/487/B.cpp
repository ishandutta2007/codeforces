#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<pair<int, int> >A, B;
int n, s, l, a[100020], f[100020], t;
int main() {
	scanf("%d%d%d", &n, &s, &l);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		A.insert(make_pair(a[i], i));
		while(A.rbegin() -> first - A.begin() -> first > s) {
			B.erase(make_pair(f[t], t));
			t++;
			A.erase(make_pair(a[t], t));
		}
		if (i >= l && A.size() >= l) {
			if (f[i - l] >= 0) {
				B.insert(make_pair(f[i - l], i - l));
			}
		}
		if (B.size() == 0) {
			f[i] = -1;
		} else {
			f[i] = B.begin() -> first + 1;
		}
	}
	printf("%d\n", f[n]);
	return 0;
}