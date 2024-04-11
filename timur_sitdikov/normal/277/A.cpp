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

const int maxn = 205;
char g[maxn][maxn], col[maxn];
int n, m;

void dfs(int s){
	int i;
	col[s] = 1;
	for(i = 0; i <= n + m; i++){
		if (g[s][i] && !col[i]){
			dfs(i);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int k, a, i, j, ans, f;
	cin >> n >> m;
	f = 0;
	for(i = 0; i < n; i++){
		cin >> k;
		if (k > 0){
			f = 1;
		}
		for(j = 0; j < k; j++){
			cin >> a;
			g[i][a + n] = g[a + n][i] = 1;
		}
	}
	if (!f){
		printf("%d\n", n);
		return 0;
	}
	ans = -1;
	for(i = 0; i < n; i++){
		if (col[i])
			continue;
		dfs(i);
		ans++;
	}
	cout << ans;
}