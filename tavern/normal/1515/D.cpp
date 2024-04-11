#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n, l, r;
int a[maxn], b[maxn], cntl[maxn], cntr[maxn], visr[maxn], tmp[maxn];

inline void solve(){
	scanf("%d%d%d", &n, &l, &r);
	
	FOR(i, 0, n)
		cntl[i] = cntr[i] = visr[i] = 0;
	
	int ans = 0;
	
	FOR(i, 0, l)
		scanf("%d", a + i), --a[i];
	FOR(i, 0, r)
		scanf("%d", b + i), --b[i];
	
	if(l > r){
		FOR(i, 0, l)
			tmp[i] = a[i];
		FOR(i, 0, r)
			a[i] = b[i];
		FOR(i, 0, l)
			b[i] = tmp[i];
		swap(l, r);
	}
	
	FOR(i, 0, l)
		++cntl[a[i]];
		
	int tot = n, cl = l, cr = r;
	
	FOR(i, 0, r){
		if(cntl[b[i]])
			visr[i] = 1, --cntl[b[i]], --cl, --cr, tot -= 2;
	}
	
	FOR(i, 0, r) if(!visr[i]){
		if(cntr[b[i]] && cr - 2 >= cl)
			visr[i] = 1, --cntr[b[i]], ++ans, tot -= 2, cr -= 2;
		else
			++cntr[b[i]];
	}
	
	//printf("tot = %d cl = %d cr = %d ans = %d\n", tot, cl, cr, ans);
	
	ans += tot / 2;
	ans += abs(cr - cl) / 2;
	printf("%d\n", ans);
	return;
	
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}