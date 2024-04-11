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

int n;
int m;
int x[2000], y[2000], t[2000], q[2000];
double p[2000], res[2000];

bool myless (int i, int j) {
	return t[i] < t[j];
}

int main() {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
        	scanf ("%d%d%d%lf", &x[i], &y[i], &t[i], &p[i]);
        	q[i] = i;
	}
	sort (q, q + n, myless);		
	double ans = 0;
	for (int i = 0; i < n; i++) {
		int I = q[i];
		res[i] = 0;
		for (int j = 0; j < i; j++) {
			int J = q[j];
			if ((x[I] - x[J]) * (x[I] - x[J]) + (y[I] - y[J]) * (y[I] - y[J]) <= ((ll)(t[I] - t[J])) * (t[I] - t[J]))	
				res[i] = max (res[i], res[j]);
		}
		res[i] += p[I];
		ans = max (ans, res[i]);
	}
	printf ("%.10f\n", ans);
	return 0;
}