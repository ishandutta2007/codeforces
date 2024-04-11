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
string s[16];
map<string, int> w;
int g[16][16];

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort (s, s + n);
	for (int i = 0; i < n; i++) w[s[i]] = i;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		g[w[a]][w[b]] = g[w[b]][w[a]] = 1;
	}
	int ans = 0, res = 0;
	for (int i = 1; i < (1 << n); i++) {
		int ok = 0, cur = 0;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (((i >> j) & 1) && ((i >> k) & 1) && g[j][k])
					ok = 1;
		for (int j = 0; j < n; j++) cur += (i >> j) & 1;
		if (!ok && cur > ans) {
			ans = cur;
			res = i;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		if ((res >> i) & 1)
			cout << s[i] << endl;
	return 0;
}