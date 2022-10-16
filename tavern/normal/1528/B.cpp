#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i <  (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)

const int maxn = 1e6 + 5;
const int INF = 998244353;

int n, ptot;
int pw_2[maxn], d_0[maxn], pri[maxn], low[maxn], cnt[maxn], pw[maxn];
bool isp[maxn];

int main(){
	scanf("%d", &n);
	pw_2[0] = 1; REP(i, 1, n) pw_2[i] = (pw_2[i - 1] << 1) % INF;
	
	d_0[0] = d_0[1] = 1; memset(isp, true, sizeof(isp)); isp[1] = 0;
	REP(i, 1, n){
		if(isp[i])
			low[pri[ptot++] = i] = i, cnt[i] = 1, low[i] = i, pw[i] = i;
		for(int j = 0; j < ptot && 1ll * pri[j] * i <= n && pri[j] <= low[i]; ++j){
			isp[pri[j] * i] = false;
			low[pri[j] * i] = pri[j];
			if(pri[j] == low[i])
				cnt[pri[j] * i] = cnt[i] + 1, pw[pri[j] * i] = pw[i] * pri[j];
			else
				cnt[pri[j] * i] = 1, pw[pri[j] * i] = pri[j];
		}
	}
	REP(i, 2, n)
		d_0[i] = 1ll * d_0[i / pw[i]] * (cnt[i] + 1) % INF;
	REP(i, 1, n)
		--d_0[i];
	int ans = 0;
	FOR(i, 0, n)
		(ans += 1ll * d_0[i] * pw_2[n - i - 1] % INF) %= INF;
	(ans += d_0[n]) %= INF;
	printf("%d\n", ans);
	return 0;
}