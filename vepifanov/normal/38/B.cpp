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

int main() {
	string sa, sb;
	cin >> sa >> sb;
	int ir = sa[0] - 'a';
	int jr = sa[1] - '1';
	int ik1 = sb[0] - 'a';
	int jk1 = sb[1] - '1';
	int ans = 0;
	for (int ik2 = 0; ik2 < 8; ik2++)
		for (int jk2 = 0; jk2 < 8; jk2++) {
			if (ik2 == ir && jk2 == jr || ik2 == ik1 && jk2 == jk1) continue;
			if (abs (ik2 - ik1) * abs (jk2 - jk1) == 2 || abs (ik2 - ir) * abs (jk2 - jr) == 2) continue;
			if (ik2 == ir || jk2 == jr) continue;
			ans++;
		}
	printf ("%d\n", ans);
	return 0;
}