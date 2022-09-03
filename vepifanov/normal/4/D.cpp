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
int m, res[5000], prev[5000];
vector<pair<ii, int> > v;

int out (int i) {
	if (i == -1) return 0;
	out (prev[i]);
	printf ("%d ", v[i].second + 1);
	return 0;
}

int main() {
	int n, w, h;
	scanf ("%d%d%d", &n, &w, &h);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		if (a > w && b > h) v.push_back (mp (mp (a, b), i));
	}
	sort (v.begin (), v.end ());
	int ans = 0, ai = -1;
	for (int i = 0; i < v.size (); i++) {
		res[i] = 1;
		prev[i] = -1;
		for (int j = 0; j < i; j++)
			if (v[j].first.first < v[i].first.first && v[j].first.second < v[i].first.second && res[i] < res[j] + 1) {
				res[i] = res[j] + 1;
				prev[i] = j;
			}
		if (res[i] > ans) {
			ans = res[i];
			ai = i;
		}
	}
	printf ("%d\n", ans);
	out (ai);
	if (ans > 0) printf ("\n");
	return 0;
}