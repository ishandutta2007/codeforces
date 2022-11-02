#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 300000;
const int bse[2] = {131, 13131};
const int MOD[2] = {int(1E9)+7, int(1E9)+9};
void exgcd(ll a, ll b, ll &x, ll &y) {
	if( b == 0 ) {
		x = 1, y = 0;
		return ;
	}
	ll x1, y1;
	exgcd(b, a%b, x1, y1);
	x = y1; y = x1 - a/b*y1;
}
ll inv(ll a, ll m) {
	ll x, y;
	exgcd(a, m, x, y);
	return (x%m + m) % m;
}
ll pw[2][MAXN + 5];
vector<pii>G[MAXN + 5];
void addedge(int u, int v, int w) {
	G[u].push_back(make_pair(v, w));
}
pll T; int pcnt; ll ans = 0;
map<pll, int>Map[MAXN + 5];
map<pll, int>::iterator it;
ll tag1[2][MAXN + 5], tag2[2][MAXN + 5];
int siz[MAXN + 5], id[MAXN + 5];
void dfs(int rt) {
	siz[rt] = 1;
	int maxize = -1, maxn;
	for(int i=0;i<G[rt].size();i++) {
		int c = G[rt][i].first;
		dfs(c);
		if( siz[c] > maxize ) {
			maxize = siz[c];
			maxn = i;
		}
		siz[rt] += siz[c];
	}
	if( maxize == -1 ) {
		id[rt] = rt;
		tag1[0][rt] = tag1[1][rt] = 1;
		tag2[0][rt] = tag2[1][rt] = 0;
		Map[rt][make_pair(0, 0)] = 1;
		return ;
	}
	id[rt] = id[G[rt][maxn].first];
	for(int i=0;i<2;i++) {
		tag1[i][rt] = tag1[i][G[rt][maxn].first] * bse[i] % MOD[i];
		tag2[i][rt] = (tag2[i][G[rt][maxn].first] * bse[i] + G[rt][maxn].second) % MOD[i];
	}
	ll INV[2] = {inv(tag1[0][rt], MOD[0]), inv(tag1[1][rt], MOD[1])};
	for(int i=0;i<G[rt].size();i++) {
		if( i == maxn ) continue;
		int c = G[rt][i].first;
		for(it=Map[id[c]].begin();it!=Map[id[c]].end();it++) {
			ll p[2] = {it->first.first, it->first.second};
			for(int j=0;j<2;j++) {
				p[j] = (p[j]*tag1[j][c]%MOD[j]*bse[j]%MOD[j] + (tag2[j][c]*bse[j]+G[rt][i].second)%MOD[j]) % MOD[j];
				p[j] = ( (p[j]-tag2[j][rt])%MOD[j] * INV[j] % MOD[j] + MOD[j] ) % MOD[j];
			}
			Map[id[rt]][make_pair(p[0], p[1])] += it->second;
		}
	}
	Map[id[rt]][make_pair(((MOD[0]-tag2[0][rt])*INV[0]%MOD[0]+MOD[0])%MOD[0], ((MOD[1]-tag2[1][rt])*INV[1]%MOD[1]+MOD[1])%MOD[1])]++;
	pll Pir = make_pair(((T.first-tag2[0][rt])*INV[0]%MOD[0]+MOD[0])%MOD[0], ((T.second-tag2[1][rt])*INV[1]%MOD[1]+MOD[1])%MOD[1]);
	if( Map[id[rt]].count(Pir) )
		ans += Map[id[rt]][Pir];
/*	printf("%d  : ", rt);
	for(it=Map[id[rt]].begin();it!=Map[id[rt]].end();it++)
		printf(" (%d, %d) ", it->first.first, it->first.second);
	puts("");*/
}
void init() {
	pw[0][0] = pw[1][0] = 1;
	for(int i=0;i<=1;i++)
		for(int j=1;j<=MAXN;j++)
			pw[i][j] = (pw[i][j-1] * bse[i]) % MOD[i];
}
char s[MAXN + 5], t[MAXN + 5];
int main() {
	init();
	int n;
	scanf("%d", &n);
	pcnt = n;
	for(int i=2;i<=n;i++) {
		int p;
		scanf("%d%s", &p, s);
		int len = strlen(s);
		for(int j=0;j<len-1;j++) {
			addedge(p, ++pcnt, s[j]-'a'+1);
			p = pcnt;
		}
		addedge(p, i, s[len-1]-'a'+1);
	}
	scanf("%s", t);
	int lenT = strlen(t);
	for(int i=lenT-1;i>=0;i--) {
		T.first = (T.first * bse[0] + t[i]-'a'+1) % MOD[0];
		T.second = (T.second * bse[1] + t[i]-'a'+1) % MOD[1];
	}
	dfs(1);
	printf("%I64d\n", ans);
}