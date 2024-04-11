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

int n = 0;
int m;
int x[1000];

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size (); i++)
		if (s[i] == '@')
			x[n++] = i;
	int m = s.size ();
	for (int i = n - 2; i >= 0; i--)
		if (x[i + 1] - x[i] < 3) {
			printf ("No solution\n");
			re 0;
		} else s.insert (x[i] + 2, ",");
	if (n == 0 || x[n - 1] + 1 == m || x[0] == 0) printf ("No solution\n"); else cout << s << endl;
	return 0;
}