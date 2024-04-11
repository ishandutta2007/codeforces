#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp push_back
#define all(a) a.begin(), a.end()
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int p = 1e9 + 7, MAXN = 1e5;

int n;
long double v[MAXN];
long double coor[MAXN];

bool check(long double M){
	long double L = -1e18, R = 1e18;
	for (int i = 0; i < n; ++i) {
		long double Ln, Rn;
		Ln = coor[i] - v[i] * M;
		Rn = coor[i] + v[i] * M;
		L = max(L, Ln), R = min(R, Rn);
	}
	return L <= R;
}

int main() {
	//read(FILENAME);
	cin >> n;
	for (int i = n; i--;) cin >> coor[i];
	for (int i = n; i--;) cin >> v[i];
	long double L = 0, R = 1e9;
	for (int i = 100; i--;) {
		long double M = (L + R) / 2;
		if (check(M)) {
			R = M;
		} else {
			L = M;
		}
	}	
	cout << fixed << R << endl;
}