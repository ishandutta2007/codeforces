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

int get_tp(char c) {
	if (c == '(') {
		return 0;
	}

	if (c == ')') {
		return 1;
	}

	if (c == '<') {
		return 2;
	}

	if (c == '>') {
		return 3;
	}

	if (c == '{') {
		return 4;
	}

	if (c == '}') {
		return 5;
	}

	if (c == '[') {
		return 6;
	}

	if (c == ']') {
		return 7;
	}

	return 8;
}


int main() {
	//freopen("input.txt", "r", stdin);
	vector <char> v;

	int ans = 0;

	char c;

	while (scanf("%c", &c) != EOF) {
		if (get_tp(c) == 8) {
			break;
		}
		if (get_tp(c) % 2 == 0) {
			v.push_back(c);
		} else if (v.empty()) {
			cout << "Impossible" << endl;
			return 0;
		} else if ((get_tp(c) ^ 1) != get_tp(v.back())) {
			ans++;
			v.pop_back();
		} else {
			v.pop_back();
		}
	}

	if (v.empty()) {
		cout << ans << endl;
	} else {
		cout << "Impossible" << endl;
	}

	return 0;
}