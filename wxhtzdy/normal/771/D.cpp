#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, dp[80][80][80][2];
char s[80];
vector<int> occ[26];

int chkmin(int &a, int b)
{
	a = min(a, b);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	rep(i, n) if (s[i] != 'V' && s[i] != 'K') s[i] = 'A';
	rep(i, n) occ[s[i] - 'A'].push_back(i);
	int v = 'V' - 'A', k = 'K' - 'A', a = 0;
	int sv = occ[v].size(), sk = occ[k].size(), sa = occ[a].size();
	rep(i, 80) rep(j, 80) rep(l, 80) rep(st, 2) dp[i][j][l][st] = INF;
	dp[0][0][0][0] = 0;
	rep(i, sv + 1) rep(j, sk + 1) rep(l, sa + 1) rep(st, 2) {
		if(i == sv && j == sk && l == sa) continue;
		if(i < sv) {
			int pos = occ[v][i], ft = 0;
			for(int ii = i; ii < sv; ii ++) if(occ[v][ii] < pos) ft++;
			for(int ii = j; ii < sk; ii ++) if(occ[k][ii] < pos) ft++;
			for(int ii = l; ii < sa; ii ++) if(occ[a][ii] < pos) ft++;
			chkmin(dp[i + 1][j][l][1], dp[i][j][l][st] + ft);
		}
		if(j < sk && !st) {
			int pos = occ[k][j], ft = 0;
			for(int ii = i; ii < sv; ii ++) if(occ[v][ii] < pos) ft++;
			for(int ii = j; ii < sk; ii ++) if(occ[k][ii] < pos) ft++;
			for(int ii = l; ii < sa; ii ++) if(occ[a][ii] < pos) ft++;
			chkmin(dp[i][j + 1][l][0], dp[i][j][l][st] + ft);
		}
		if(l < sa) {
			int pos = occ[a][l], ft = 0;
			for(int ii = i; ii < sv; ii ++) if(occ[v][ii] < pos) ft++;
			for(int ii = j; ii < sk; ii ++) if(occ[k][ii] < pos) ft++;
			for(int ii = l; ii < sa; ii ++) if(occ[a][ii] < pos) ft++;
			chkmin(dp[i][j][l + 1][0], dp[i][j][l][st] + ft);
		}
	}
	printf("%d", min(dp[sv][sk][sa][0], dp[sv][sk][sa][1]));
	return 0;
}