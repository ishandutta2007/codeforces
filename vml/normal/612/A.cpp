#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <cstring>
#include <ctime>
#include <map>
#include <bitset>
#define ld double
#define ll long long
#define mp make_pair
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

int main() {
	int n, p, q;

	cin >> n >> p >> q;

	string s;

	cin >> s;

	for (int i = 0; i <= n / p; i++) {
		if ((n - i * p) % q == 0) {
			int x = i;
			int y = (n - i * p) / q;

			int pos = 0;

			cout << x + y << endl;

			while (x != 0) {
				for (int j = pos; j < pos + p; j++) {
					cout << s[j];
				}
				pos += p;
				x--;
				cout << endl;
			}

			while (y != 0) {
				for (int j = pos; j < pos + q; j++) {
					cout << s[j];
				}
				pos += q;
				y--;
				cout << endl;
			}

			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}