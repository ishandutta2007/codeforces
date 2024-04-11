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

const int maxn = 405;

int n, INF;
int pw_2[maxn];
int f[maxn][maxn], binom[maxn][maxn];

int main(){
	scanf("%d%d", &n, &INF);
	
	REP(i, 0, n){
		binom[i][0] = 1;
		REP(j, 1, i)
			binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % INF;
	}
	
	pw_2[0] = 1; REP(i, 1, n) pw_2[i] = (pw_2[i - 1] << 1) % INF;
	
	f[0][0] = 1;
	FOR(i, 0, n) REP(j, 0, i) if(f[i][j]){
		//printf("i = %d j = %d f = %d\n", i, j, f[i][j]);
		REP(k, 1, n) if(i + k + 1 <= n + 1)
			(f[i + k + 1][j + k] += 1ll * f[i][j] * binom[j + k][k] % INF * pw_2[k - 1] % INF) %= INF;
	}
	
	int ans = 0;
	REP(j, 0, n)
		(ans += f[n + 1][j]) %= INF/*, printf("j = %d f = %d\n", j, f[n + 1][j])*/;
	printf("%d\n", ans);
	return 0;
}