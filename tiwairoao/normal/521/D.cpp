#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

const int MAXN = 100000;

struct node{
	ll a, b; int i; node() {}
	node(ll _a, ll _b, int _i) : a(_a), b(_b), i(_i) {}
	friend bool operator < (const node &a, const node &b) {
		return (long double)a.a * b.b < (long double)b.a * a.b;
	}
};

vector<int>ans;
vector<node>v;
vector<pii>c[MAXN + 5];
pii d[MAXN + 5];

int a[MAXN + 5], t[MAXN + 5];
bool cmp(int x, int y) {return t[x] < t[y];}
int main() {
	int k, n, m; scanf("%d%d%d", &k, &n, &m);
	for(int i=1;i<=k;i++) scanf("%d", &a[i]), d[i] = mp(a[i], 0);
	for(int i=1;i<=n;i++) {
		int x, b; scanf("%d%d%d", &t[i], &x, &b);
		if( t[i] == 1 ) {
			if( b > d[x].fi )
				d[x] = mp(b, i);
		} else if( t[i] == 2 ) {
			c[x].push_back(mp(b, i));
		} else v.push_back(node(b, 1, i));
	}
	
	for(int i=1;i<=k;i++) {
		if( d[i].fi != a[i] )
			c[i].push_back(mp(d[i].fi - a[i], d[i].se));
		sort(c[i].begin(), c[i].end());
		
		ll s = a[i];
		for(int j=c[i].size()-1;j>=0;j--) {
			v.push_back(node(s + c[i][j].fi, s, c[i][j].se));
			s += c[i][j].fi;
		}
	}
	
	sort(v.begin(), v.end());
	for(int i=v.size()-1;v.size()-i<=m&&i>=0;i--)
		ans.push_back(v[i].i);
	
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
}