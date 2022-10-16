#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
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

const int maxn = 3e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, top;
int h[maxn], b[maxn];
int mn[maxn];
ll g[maxn], f[maxn], pre[maxn];

int main(){
	scanf("%d", &n);
	REP(i, 1, n)
		scanf("%d", h + i);
	REP(i, 1, n)
		scanf("%d", b + i);
	
	g[++top] = 0;
	mn[top] = n + 1;
	pre[top] = -INF;
	REP(i, 1, n){
		ll p = -INF;
		for(; top && mn[top] > h[i]; --top)
			p = max(p, g[top]);
		mn[++top] = h[i];
		g[top] = p;
		pre[top] = max(top > 1 ? pre[top - 1] : -INF, g[top] + b[i]);
		if(!top)
			f[i] = 0;
		else
			f[i] = pre[top];
		mn[++top] = n + 1;
		g[top] = f[i];
		pre[top] = max(top > 1 ? pre[top - 1] : -INF, g[top]);
	}
	
	printf("%lld\n", f[n]);
	return 0;
}