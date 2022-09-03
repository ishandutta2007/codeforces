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

char w[100];

int main() {
	int tt;
	scanf ("%d", &tt);
	gets (w);
	for (int it = 1; it <= tt; it++) {
		gets (w);
		string s(w);
		int ok = 0, x = 0, y = 0;
		for (int i = 1; i < s.size (); i++)
			if (s[i] == 'C' && s[i - 1] >= '0' && s[i - 1] <= '9')
				ok = i;
		if (ok > 0) {	
			s[0] = s[ok] = ' ';
			istringstream in(s);
			in >> y >> x;
			int q = 26, l = 1;
			while (q < x) {
				x -= q;
				q *= 26;
				l++;
			}
			for (int i = 0; i < l; i++) {
				 q /= 26;
				 for (int j = 0; j < 26; j++)
				 	if (x <= q) {
				 		printf ("%c", char ('A' + j));
				 		break;
				 	} else x -= q;
			}
			printf ("%d\n", y);
		} else {
			int k = 0;
			while (s[k] >= 'A' && s[k] <= 'Z') k++;
			for (int l = k; l < s.size (); l++)
				y = y * 10 + s[l] - '0';
			int q = 26;
			for (int i = 0; i + 1 < k; i++) {
				x += q;
				q *= 26;
			}
			for (int i = 0; i < k; i++) {
				q /= 26;
				x += (s[i] - 'A') * q;
			}
			printf ("R%dC%d\n", y, x + 1);
		}
	}
	return 0;
}