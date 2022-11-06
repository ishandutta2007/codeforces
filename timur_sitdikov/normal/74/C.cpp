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

const int MAXN = 4000005;

int g[MAXN][2];
char col[MAXN];

void dfs(int s){
	col[s] = 1;
	for(int i = 0; i < 2; i++){
		if (g[s][i] != -1 && !col[g[s][i]]){
			dfs(g[s][i]);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, top, i, ind1, ind2;
	cin >> n >> m;
	if (n < m){
		swap(n, m);
	}
	top = 2 * (m + n) - 4;

	for(i = 0; i < top; i++){
		g[i][0] = g[i][1] = -1;
	}

	for(i = 0; i <= n - m; i++){
		ind1 = i;
		ind2 = n + m - 1 + i + m - 2;
		g[ind1][0] = ind2;
		g[ind2][0] = ind1;
	}

	for(i = n - m + 1; i < n - 1; i++){
		ind1 = i;
		ind2 = n + m - 1 + n - 1 + (n - 2 - i);
		g[ind1][0] = ind2;
		g[ind2][0] = ind1;
	}

	for(i = 1; i < m - 1; i++){
		ind1 = n + i - 1;
		ind2 = n + m - 1 + (m - 2 - i);
		g[ind1][0] = ind2;
		g[ind2][0] = ind1;
	}

	for(i = 1; i <= m - 1; i++){
		ind1 = i;
		ind2 = n + i - 1;
		g[ind1][1] = ind2;
		g[ind2][1] = ind1;
	}

	for(i = m; i <= n - 1; i++){
		ind1 = i;
		ind2 = n + m - 1 + (i - m);
		g[ind1][1] = ind2;
		g[ind2][1] = ind1;
	}

	for(i = 1; i < m - 1; i++){
		ind1 = n + m - 1 + n - 1 + i - 1;
		ind2 = n + m - 1 + (i + n - m - 1);
		g[ind1][1] = ind2;
		g[ind2][1] = ind1;
	}

	int ans = 0;

	for(i = 0; i < top; i++){
		if (!col[i]){
			ans++;
			dfs(i);
		}
	}

	cout << ans;
}