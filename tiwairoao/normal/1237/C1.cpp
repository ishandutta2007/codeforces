#include<set>
#include<map>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> pii;
const int MAXN = 50000;
set<pii>sx;
map<int, set<pii> >sy;
map<pii, set<pii> >sz;
int x[MAXN + 5], y[MAXN + 5], z[MAXN + 5];
void insert(int i) {
	sx.insert(mp(x[i], i));
	sy[x[i]].insert(mp(y[i], i));
	sz[mp(x[i], y[i])].insert(mp(z[i], i));
}
void erase(int i) {
	sx.erase(mp(x[i], i));
	sy[x[i]].erase(mp(y[i], i));
	sz[mp(x[i], y[i])].erase(mp(z[i], i));
}
bool tag[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d", &x[i], &y[i], &z[i]), insert(i);
	for(int i=1;i<=n;i++) {
		if( !tag[i] ) {
			tag[i] = true, erase(i);
			int dx, dy, ans;
			if( sx.rbegin()->first < x[i] )
				dx = sx.rbegin()->first;
			else dx = sx.lower_bound(mp(x[i], 0))->first;
			if( sy[dx].rbegin()->first < y[i] )
				dy = sy[dx].rbegin()->first;
			else dy = sy[dx].lower_bound(mp(y[i], 0))->first;
			if( sz[mp(dx, dy)].rbegin()->first < z[i] )
				ans = sz[mp(dx, dy)].rbegin()->second;
			else ans = sz[mp(dx, dy)].lower_bound(mp(z[i], 0))->second;
			tag[ans] = true, erase(ans);
			printf("%d %d\n", ans, i);
		}
	}
}