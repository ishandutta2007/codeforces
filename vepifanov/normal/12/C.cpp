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
map<string, int> all;
vector<int> v;
int x[100];

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	for (int i = 0; i < m; i++) {	
		string s;
		cin >> s;
		if (all.find (s) == all.end ()) all[s] = 1; else all[s]++;
	}
	for (map<string, int>::iterator it = all.begin (); it != all.end (); it++) v.push_back (it->second);
	sort (v.begin (), v.end ());
	int a1 = 0, a2 = 0;
	for (int i = v.size () - 1, j = 0; i >= 0; i--, j++) a1 += v[i] * x[j];
	for (int i = v.size () - 1, j = n - 1; i >= 0; i--, j--) a2 += v[i] * x[j];
	printf ("%d %d\n", a1, a2);
	return 0;
}