#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

const string name[5] = {"S", "M", "L", "XL", "XXL"};

int n;
int m;
int c[5];

int main() {
	for (int i = 0; i < 5; i++) cin >> c[i];
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int k = 0;
		if (s == "M") k = 1;
		if (s == "L") k = 2;
		if (s == "XL") k = 3;
		if (s == "XXL") k = 4;
		int ok = 0;
		for (int j = 0; j < 5 && !ok; j++)
			for (int t = 1; t >= -1 && !ok; t -= 2)
				if (k + j * t >= 0 && k + j * t < 5 && c[k + j * t]) {
					cout << name[k + j * t] << endl;
					c[k + j * t]--;
					ok = 1;
				}
	}
	return 0;
}