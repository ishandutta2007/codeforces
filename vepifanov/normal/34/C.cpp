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
string s;
int use[1001];

int main() {
	cin >> s;
	for (int i = 0; i < s.size (); i++)
		if (s[i] == ',') s[i] = ' ';
	stringstream in (s);
	int x;
	while (in >> x) use[x] = 1;
	int f = 1, l = -1;
	for (int i = 1; i <= 1000; i++)
		if (use[i]) {
			if (l == -1) l = i;
			if (i == 1000 || !use[i + 1]) {
				if (!f) printf (",");
				f = 0;
				if (l != i) printf ("%d-%d", l, i); else printf ("%d", i);
				l = -1;
			}
		}
	printf ("\n");
	return 0;
}