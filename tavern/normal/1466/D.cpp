#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int n;
int a[maxn], deg[maxn];

inline void solve(){
	scanf("%d", &n);
	ll ans = 0;
	FOR(i, 0, n){
		scanf("%d", a + i);
		deg[i] = 0;
		ans += a[i];
	}
	FOR(i, 1, n){
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		++deg[u], ++deg[v];
	}
	set<pii, greater<pii> > s;
	FOR(i, 0, n) if(deg[i] != 1)
		s.insert(MP(a[i], i)), --deg[i];
	REP(i, 1, n - 1){
		printf("%lld ", ans);
		if(s.size()){
			pii p = *s.begin();
			ans += p.fst;
			--deg[p.snd]; 
			if(!deg[p.snd])
				s.erase(*s.begin());
		}
	}
	puts("");
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve()); 
	return 0;
}