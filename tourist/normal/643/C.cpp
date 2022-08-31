#include<stdio.h>
#include<cassert>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

double sum[N], sd[N], so[N];

//double dp[55][N];

int a[N];
int n, k;

double f[N], f2[N];

double ci[N], cj[N], ki[N], xj[N];

/*double calc(int i, int j) {
	double res = sd[j + 1] - sd[i];
	res -= sum[i] * (so[j + 1] - so[i]);
//	cout << i << " " << j << " " << res << endl;

	return res;
}*/


double calc2(int i, int j) {
//	cout << i << " " << j << " " << ci[i] + cj[j] + ki[i] * xj[j] << endl;
	return ci[i] + cj[j] + ki[i] * xj[j];
}

int bad(int i, int j, int k) {
	double xr = (ci[j] - ci[k]) / (ki[k] - ki[j]);

	double xl = (ci[i] - ci[j]) / (ki[j] - ki[i]);

	return xr <= xl;
}



int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	sum[0] = 0;
	for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];

	sd[0] = 0;
	for (int i = 0; i < n; i++) sd[i + 1] = sd[i] + (sum[i + 1] / 1. / a[i]);

	so[0] = 0;
	for (int i = 0; i < n; i++) so[i + 1] = so[i] + (1. / a[i]);

/*	for (int i = 0; i <= k; i++) for (int j = 0; j <= n; j++) dp[i][j] = 1e50;
	dp[0][0] = 0;


	for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) for (int u = j; u < n; u++)
		dp[i + 1][u + 1] = min(dp[i + 1][u + 1], dp[i][j] + calc(j, u));

	cout << dp[k][n] << endl;*/


	for (int i = 0; i <= n; i++) f[i] = 1e50;
	f[0] = 0;

	for (int it = 0; it < k; it++) {

		for (int i = 0; i < n; i++) {
			
			cj[i] = sd[i + 1];
		
			ci[i] = -sd[i] + sum[i] * so[i] + f[i];
		
			ki[i] = -sum[i];
			
			xj[i] = so[i + 1];
		}

	
		vector<int> e;
		int u = 0;
		for (int i = 0; i < n; i++) {
			while (e.size() >= 2 && bad(e[e.size() - 2], e.back(), i)) e.pop_back();
			e.pb(i);
//			f2[i + 1] =1e50;
			
//			for (int j = 0; j < e.size(); j++) f2[i + 1] = min(f2[i + 1], calc2(e[j], i));
			while (u >= e.size()) u--;
			
			while (u + 1 < e.size() && calc2(e[u], i) >= calc2(e[u + 1], i)) u++;
			f2[i + 1] = calc2(e[u], i);
		}
		for (int i = 0; i <= n; i++) f[i] = f2[i];
	}	

	printf("%.15lf\n", f[n]);

//	assert(fabs(dp[k][n] - f2[n]) < 1e-5);


	return 0;
}