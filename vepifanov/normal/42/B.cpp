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
#define j1 j574895

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
int i1, j1, i2, j2, i3, j3, i4, j4;

int check (int i1, int j1, int i2, int j2, int i3, int j3) {
	if (i1 == i2 && i1 == i3 && j3 >= min (j1, j2) && j3 <= max (j1, j2)) re 1;
	if (j1 == j2 && j1 == j3 && i3 >= min (i1, i2) && i3 <= max (i1, i2)) re 1;
	re 0;
}                                                     

int main() {
	string p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	i1 = p1[0] - 'a'; j1 = p1[1] - '1';
	i2 = p2[0] - 'a'; j2 = p2[1] - '1';
	i3 = p3[0] - 'a'; j3 = p3[1] - '1';
	i4 = p4[0] - 'a'; j4 = p4[1] - '1';
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i4 + i >= 0 && i4 + i < 8 && j4 + j >= 0 && j4 + j < 8) {
				int ii = i4 + i, jj = j4 + j;
				int ok = 0;
				if (!check (ii, jj, i1, j1, i3, j3) && (ii == i1 || jj == j1) && (ii != i1 || jj != j1)) ok = 1;
				if (!check (ii, jj, i2, j2, i3, j3) && (ii == i2 || jj == j2) && (ii != i2 || jj != j2)) ok = 1;
				if (abs (ii - i3) <= 1 && abs (jj - j3) <= 1) ok = 1;
				if (!ok) {
					printf ("OTHER\n");
					re 0;
				}
			}
	printf ("CHECKMATE\n");
	return 0;       
}