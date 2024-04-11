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
set<int> all;
int use[101];

int main() {
	int n, m;
	cin >> n >> m;
	memset (use, 0, sizeof (use));
	int r = 0;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		if (s == "alloc") {
			int l, OK = 0;
			cin >> l;
			for (int i = 0; i + l <= m; i++) {
				int ok = 1;
				for (int j = 0; j < l; j++)
					if (use[i + j]) ok = 0;
				if (ok) {
					OK = 1;
					r++;
					for (int j = 0; j < l; j++)
						use[i + j] = r;
					all.insert (r);
					printf ("%d\n", r);
					break;
				}
			}
			if (!OK) cout << "NULL" << endl;
		} else                   
		if (s == "erase") {
			int x;
			cin >> x;
			if (all.find (x) == all.end ()) cout << "ILLEGAL_ERASE_ARGUMENT" << endl; else {
				all.erase (x);
				for (int j = 0; j < m; j++)
					if (use[j] == x)
						use[j] = 0;
			}
		} else {
			int mm = 0;
			for (int j = 0; j < m; j++)
				if (use[j] != 0) {
					use[mm] = use[j];
					mm++;
				}
			for (int j = mm; j < m; j++)
				use[j] = 0;
		}
	}
	
	return 0;
}