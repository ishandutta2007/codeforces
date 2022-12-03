#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <sstream>
#include <set>
#include <time.h>
#include <memory.h>
#include <queue>
#include <bitset>
#include <functional>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define SORT(x) sort(all(x))
#define UNIQUE(x) SORT(x),(x).resize(unique(all(x))-(x).begin())
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef long long ll;

const double pi = acos(-1.0);

ll gcd(ll x, ll y) {
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	if (x < y) swap(x, y);
	while (y) {
		ll t = y;
		y = x % y;
		x = t;
	}
	return x;
}

char s[1234567];
char g[32];
int next[26];

char f[27];

bool wasnt[26];

map<int, int> ha;
map<int, int>::iterator it;

int main () {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif
	gets(s);
	int n = strlen(s);
	REP (i, 26) {
		f[i] = i + 'a';
		wasnt[i] = true;
	}
	int m;
	scanf("%d\n", &m);
	vector<int> in;
	REP (i, m) {
		gets(g);

		//int ans = 0;
		//set<char> aaa;
		//REP (j, strlen(g))
		//	aaa.insert(g[j]);
		//REP (q, n)
		//	FOR (w, q, n) {
		//		if (q && aaa.count(s[q-1])) continue;
		//		if (w != n-1 && aaa.count(s[w+1])) continue;
		//		set<int> bbb;
		//		FOR (e, q, w+1)
		//			bbb.insert(s[e]);
		//		vector<int> aa  (all(aaa));
		//		vector<int> bb (all(bbb));

		//		if (aa == bb) ++ans;
		//	}		
		//cout << ans << endl;

		int mask = 0;
		for (int j = 0; g[j]; ++j)
			mask |= 1<<(g[j]-'a');
		ha[mask] = 0;
		in.pb(mask);
	}
	FORD (i, n-1, 0) {
		REP (j, 26)
			if (f[j] == s[i]) {				
				FORD(k, j, 1)
					f[k] = f[k-1];
				f[0] = s[i];
				break;
			}
		wasnt[s[i]-'a'] = false;
		char bad = i ? s[i-1] : '$';
		int mask = 0;
		REP (j, 26) {
			if (f[j] == bad) break;
			if (wasnt[f[j]-'a']) break;
			mask |= 1<<(f[j]-'a');
			it = ha.find(mask);
			if (it == ha.end()) continue;
			it->Y++;
		}
	}
	REP (i, sz (in)) 
		cout << ha[in[i]] << endl;
#ifdef LocalHost
	cout << "--FINISHED--" << endl;
	while (1);
#endif
	return 0;
}