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
vii v;
string s;

int main() {
	cin >> n;
	cin >> s;
	s = "+" + s;
	int i = 0;
	while (i < sz (s)) {	
		int q = 1, x = 0, f = 0;
		if (s[i] == '-') q = -1; 
		i++;
		if (s[i] >= '0' && s[i] <= '9') {
			while (s[i] >= '0' && s[i] <= '9') {	
				x = x * 10 + s[i] - '0';
				i++;
			}
			i++;
	        } else x = 1;
		if (s[i] == '+') f = 1;
		i += 3;
		v.pb (mp (x * q, 1 - f));
	}
	sort (all (v));
	int ans = 0;
	for (int i = 0; i < sz (v); i++)
		if (v[i].se)
			ans += v[i].fi * (n++);
		else
			ans += v[i].fi * (++n);
	printf ("%d\n", ans);
	return 0;
}