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

const string p[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int n;
int m;

int get (string s) {
	for (int i = 0; i < 12; i++)
		if (p[i] == s)
			re i;
	re -1;
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int x = get (a);
	int y = get (b);
	int z = get (c);
	if ((y - x + 12) % 12 == 4 && (z - y + 12) % 12 == 3) printf ("major\n"); else
	if ((x - y + 12) % 12 == 4 && (z - x + 12) % 12 == 3) printf ("major\n"); else
	if ((x - z + 12) % 12 == 4 && (y - x + 12) % 12 == 3) printf ("major\n"); else
	if ((z - x + 12) % 12 == 4 && (y - z + 12) % 12 == 3) printf ("major\n"); else
	if ((z - y + 12) % 12 == 4 && (x - z + 12) % 12 == 3) printf ("major\n"); else
	if ((y - z + 12) % 12 == 4 && (x - y + 12) % 12 == 3) printf ("major\n"); else
	if ((y - x + 12) % 12 == 3 && (z - y + 12) % 12 == 4) printf ("minor\n"); else
	if ((x - y + 12) % 12 == 3 && (z - x + 12) % 12 == 4) printf ("minor\n"); else
	if ((x - z + 12) % 12 == 3 && (y - x + 12) % 12 == 4) printf ("minor\n"); else
	if ((z - x + 12) % 12 == 3 && (y - z + 12) % 12 == 4) printf ("minor\n"); else
	if ((z - y + 12) % 12 == 3 && (x - z + 12) % 12 == 4) printf ("minor\n"); else
	if ((y - z + 12) % 12 == 3 && (x - y + 12) % 12 == 4) printf ("minor\n"); else printf ("strange\n");
	return 0;
}