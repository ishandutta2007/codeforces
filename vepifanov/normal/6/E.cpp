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
int qax[100000], qay[100000], qbx[100000], qby[100000], x[100000];
vector<pair<int, int> > v;

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	int la = 0, ra = 0, lb = 0, rb = 0, ans = -1, k = 0;
	for (int i = 0; i < n; i++) {
		while (ra > la && qax[ra - 1] > x[i]) ra--;
		qax[ra] = x[i];
		qay[ra] = i;
		ra++;
		while (rb > lb && qbx[rb - 1] < x[i]) rb--;
		qbx[rb] = x[i];
		qby[rb] = i;
		rb++;
		while (qax[la] + m < qbx[lb]) {
			if (qay[la] == k) la++;
			if (qby[lb] == k) lb++;
			k++;
		}
		if (i - k + 1 > ans) {
			ans = i - k + 1;
			v.clear ();
		}
		if (i - k + 1 == ans) v.push_back (make_pair (k + 1, i + 1));	
	}	
	printf ("%d %d\n", ans, v.size ());
	for (int i = 0; i < v.size (); i++)
		printf ("%d %d\n", v[i].first, v[i].second);
	return 0;
}