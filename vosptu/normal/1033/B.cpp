#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

int main() {
	int t;
	long long a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a - b != 1) {
			cout << "NO" << endl;
		}else {
			long long x = a + b;
			bool fi = false;
			for (long long i = 2; i * i <= x; i++)
				if (x % i == 0) {
					fi = true;
				}
			if (fi) {
				printf("NO\n");
			}else {
				printf("YES\n");
			}
		}
	}
}