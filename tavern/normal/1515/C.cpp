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

const int maxn = 1e5 + 5;

int n, m, x;
int a[maxn], sum[maxn], b[maxn], ord[maxn];

inline bool cmp(const int &i, const int &j){ return a[i] < a[j]; }

inline void solve(){
	scanf("%d%d%d", &n, &m, &x);
	FOR(i, 0, n)
		scanf("%d", a + i), ord[i] = i;
	sort(ord, ord + n, cmp);
	
	priority_queue<pii, vector<pii>, greater<pii> > que;
	
	FOR(i, 0, m)
		sum[i] = 0, que.PH(MP(sum[i], i));
	FOR(i, 0, n){
		int j = que.top().snd; que.pop();
		b[ord[i]] = j;
		sum[j] += a[ord[i]];
		que.PH(MP(sum[j], j));
	}
	
	int mx = 0, mn = 0x3f3f3f3f;
	FOR(i, 0, m)
		mx = max(mx, sum[i]), mn = min(mn, sum[i]);
	
	if(mx - mn > x){
		puts("NO");
	}
	else{
		puts("YES");
		FOR(i, 0, n)
			printf("%d ", b[i] + 1);
		puts("");
	}
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}