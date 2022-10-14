#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m,q,nxt;
map<int,int> f[N];
set<int> cr[N];
map<PII,int> sv,id;
int find(int x,int c) {
	return f[c][x]==x?x:f[c][x]=find(f[c][x],c);
}
void unite(int x,int y,int c) {
	if (!f[c][x]) f[c][x]=x;
	if (!f[c][y]) f[c][y]=y;
	f[c][find(y,c)]=find(x,c);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		unite(x,y,c);
	}
	rep(c,1,m+1) {
		for (auto x:f[c]) {
			PII fa=mp(c,find(x.fi,c));
			if (!id[fa]) id[fa]=++nxt;
			cr[x.fi].insert(id[fa]);
		}
	}
	scanf("%d",&q);
	while (q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (SZ(cr[x])>SZ(cr[y])) swap(x,y);
		if (!sv.count(mp(x,y))) {
			for (auto c:cr[x]) {
				if (cr[y].find(c)!=cr[y].end()) sv[mp(x,y)]++;
			}
		}
		printf("%d\n",sv[mp(x,y)]);
	}
}