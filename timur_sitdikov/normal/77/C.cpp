#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 100005;

vector<int> g[MAXN];
int prv[MAXN];
long long cnt[MAXN];
long long dp[MAXN];
int ss;

pair<long long, int> vals[MAXN];
int top;

void dfs(int s){
	int i, to;
	for(i = 0; i < (int)g[s].size(); i++){
		to = g[s][i];
		if (prv[s] == to)
			continue;
		prv[to] = s;
		dfs(to);
	}
	top = 0;
	for(i = 0; i < (int)g[s].size(); i++){
		to = g[s][i];
		if (prv[s] == to)
			continue;
		vals[top++] = mp(dp[to], to);
	}
	sort(vals, vals + top);
	reverse(vals, vals + top);
	int lim = top, lim1;
	if (s == ss){
		lim1 = cnt[s];
	}
	else{
		lim1 = cnt[s] - 1;
	}
	lim = min(lim, lim1);
	for(i = 0; i < lim; i++){
		if (vals[i].first == 0)
			break;
		dp[s] += vals[i].first + 2;
		cnt[s]--;
		cnt[vals[i].second]--;
	}
	long long dif;
	for(i = 0; i < (int)g[s].size(); i++){
		to = g[s][i];
		if (prv[s] == to)
			continue;
		if (s == ss && cnt[s] == 0)
			break;
		if (s != ss && cnt[s] <= 1)
			break;
		dif = cnt[to];
		if (s == ss){
			dif = min(dif, cnt[s]);
		}
		else{
			dif = min(dif, cnt[s] - 1);
		}
		cnt[to] -= dif;
		cnt[s] -= dif;
		dp[s] += 2 * dif;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, i, a, b;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%I64d", &cnt[i]);
	}
	for(i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	scanf("%d", &ss);
	dfs(ss);
	printf("%I64d", dp[ss]);
}