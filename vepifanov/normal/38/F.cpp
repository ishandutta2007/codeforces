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
vector<string> dic[31];
map<string, int> all[31];
int cnt[31][1001], ct, cwas[31][1001];
int was[31][1001];
pair<int, ii> res[31][1001];

pair<int, ii> go (int i, int j) {
	if (was[i][j]) re res[i][j];
	was[i][j] = 1;
	int tmp = 0, a = 0, b = 0;
	for (int c = 'a'; c <= 'z'; c++) {
		string sc = "";
		sc += c;
		if (all[i + 1].count (sc + dic[i][j])) {
			pair<int, ii> cur = go (i + 1, all[i + 1][sc + dic[i][j]]);
			swap (cur.se.fi, cur.se.se);
			if (tmp == 0 && cur.fi == 0 || tmp == 1 && cur.fi == 0 && (cur.se.fi > a || cur.se.fi == a && cur.se.se < b)) {
				tmp = 1;
				a = cur.se.fi;
				b = cur.se.se;
			}
			if (tmp == 0 && cur.fi == 1 && (cur.se.fi > a || cur.se.fi == a && cur.se.se < b)) {
				a = cur.se.fi;
				b = cur.se.se;
			}
		}
		if (all[i + 1].count (dic[i][j] + sc)) {
			pair<int, ii> cur = go (i + 1, all[i + 1][dic[i][j] + sc]);
			swap (cur.se.fi, cur.se.se);
			if (tmp == 0 && cur.fi == 0 || tmp == 1 && cur.fi == 0 && (cur.se.fi > a || cur.se.fi == a && cur.se.se < b)) {
				tmp = 1;
				a = cur.se.fi;
				b = cur.se.se;
			}
			if (tmp == 0 && cur.fi == 1 && (cur.se.fi > a || cur.se.fi == a && cur.se.se < b)) {
				a = cur.se.fi;
				b = cur.se.se;
			}
		}
	}
	int sum = 0, mx = 0;
	for (int k = 0; k < sz (dic[i][j]); k++) {
		sum += dic[i][j][k] - 'a' + 1;
		mx = max (mx, dic[i][j][k] - 'a' + 1);
	}
	b += sum * mx + cnt[i][j];
	res[i][j] = mp (tmp, mp (a, b));
//	cout << dic[i][j] << " " << tmp << " " << a << " " << b << " " << sum << " " << mx << " " << cnt[i][j] << endl;
//	cout << dic[i][j] << " " << 
	re res[i][j];			
}

int add (int l, string s) {
	if (all[l].count (s)) {	
		if (cwas[l][all[l][s]] < ct) {
			cnt[l][all[l][s]]++;
			cwas[l][all[l][s]] = ct;
		}
		re 0;
	}
	cnt[l][sz (dic[l])] = 1;
	all[l][s] = sz (dic[l]);
	cwas[l][all[l][s]] = ct;
	dic[l].pb (s);
	re 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ct++;
		string s;
		cin >> s;
		for (int i = 0; i < sz (s); i++)
			for (int j = i; j < sz (s); j++)
				add (j - i, s.substr (i, j - i + 1));
	}
	int tmp = 0, a = -1, b = 0;
	for (int i = 0; i < sz (dic[0]); i++) {
		pair<int, ii> cur = go (0, i);
		swap (cur.se.fi, cur.se.se);
		if (tmp == 0 && cur.fi == 0 || tmp == 1 && cur.fi == 0 && (cur.se.fi > a || cur.se.fi == a && cur.se.se < b)) {
			tmp = 1;
			a = cur.se.fi;
			b = cur.se.se;
		}
		if (tmp == 0 && cur.fi == 1 && (cur.se.fi > a || cur.se.fi == a && cur.se.se < b)) {
			a = cur.se.fi;
			b = cur.se.se;
		}

	}
	if (!tmp) printf ("Second\n"); else printf ("First\n");
	printf ("%d %d\n", a, b);
	return 0;
}