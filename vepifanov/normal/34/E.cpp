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

const double eps = 1e-7;

int n;
double t, x[10], v[10], m[10];

int main() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> x[i] >> v[i] >> m[i];
	while (true) {
		double rt = 1e9;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j)  {
					double dt = (x[j] - x[i]) / (v[i] - v[j]);
					if (dt < eps) continue;
					if (dt < rt) rt = dt;
				}
		if (rt > t + eps) break;
		t -= rt;
		for (int i = 0; i < n; i++) x[i] += rt * v[i];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (fabs (x[i] - x[j]) < eps)  {
					double v1 = ((m[i] - m[j]) * v[i] + 2 * m[j] * v[j]) / (m[i] + m[j]);
					double v2 = ((m[j] - m[i]) * v[j] + 2 * m[i] * v[i]) / (m[i] + m[j]);
					v[i] = v1;
					v[j] = v2;
				}
	}               
	for (int i = 0; i < n; i++) x[i] += t * v[i];
	for (int i = 0; i < n; i++) printf ("%.10f\n", x[i]);
	return 0;
}