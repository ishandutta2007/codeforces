#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int v[100000], can[100001];

int get (string s) {
	int n = sz (s);
	if (n >= 4 && s.substr (n - 4) == "lios") re 1;
	if (n >= 3 && s.substr (n - 3) == "etr") re 2;
	if (n >= 6 && s.substr (n - 6) == "initis") re 3;
	if (n >= 5 && s.substr (n - 5) == "liala") re 4;
	if (n >= 4 && s.substr (n - 4) == "etra") re 5;
	if (n >= 6 && s.substr (n - 6) == "inites") re 6;
	re 0;
}

int main () {
	string s;
	while (cin >> s) v[n++] = get (s);
	int ok = 0;
	for (int i = 0; i < n; i++)
		if (v[i] == 2 || v[i] == 5) {
			can[i] = 1;
			int j = i;
			while (j > 0 && v[j - 1] == v[i] - 1) { j--; can[j] = 1; }
			j = i;
			while (j + 1 < n && v[j + 1] == v[i] + 1) { j++; can[j] = 1; }
			ok++;
		}
	if (ok > 1) { printf ("NO\n"); re 0; }
	if (n == 1 && v[0] > 0) { printf ("YES\n"); re 0; }
	for (int i = 0; i < n; i++)
		if (!can[i]) {
			printf ("NO\n");
			re 0;
		}
	printf ("YES\n");	
	return 0;
}