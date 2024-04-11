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

char w[100][100];

int main() {
        int n, m;
        scanf ("%d%d\n", &n, &m);
        int li = n, lj = m, ri = 0, rj = 0;
        for (int i = 0; i < n; i++) {
        	gets (w[i]);
        	for (int j = 0; j < m; j++)
        		if (w[i][j] == '*') {
        			li = min (li, i);
        			ri = max (ri, i);
        			lj = min (lj, j);
        			rj = max (rj, j);
        		}
        }
	for (int i = li; i <= ri; i++) {
		for (int j = lj; j <= rj; j++)
			printf ("%c", w[i][j]);
		printf ("\n");
	}
	return 0;
}