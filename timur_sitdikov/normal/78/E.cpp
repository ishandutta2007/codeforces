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

char c[15][15];

char g[1000][1000];

vector<int> v[2][15][15];

queue<pair<int, int> > qq;

int tt[15][15], tt1[15][15], n, nn[2];

int mt[1000], used[1000];

void set_tt(int i0, int j0){
	int i, j, i1, j1;
	qq.push(mp(i0, j0));
	while(!qq.empty()){
		i0 = qq.front().first;
		j0 = qq.front().second;
		qq.pop();
		for(i = -1; i <= 1; i++){
			for(j = -1; j <= 1; j++){
				if (abs(i) + abs(j) != 1)
					continue;
				i1 = i + i0;
				j1 = j + j0;
				if (tt[i1][j1] > tt[i0][j0] + 1){
					tt[i1][j1] = tt[i0][j0] + 1;
					qq.push(mp(i1, j1));
				}
			}
		}
	}
}


void go(int i0, int j0){
	if (v[0][i0][j0].size() == 0)
		return;
	int i, j, k1, k2, i1, j1, t;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			tt1[i][j] = -1;
		}
	}
	tt1[i0][j0] = 0;
	int i00 = i0, j00 = j0;
	qq.push(mp(i0, j0));
	while(!qq.empty()){
		i0 = qq.front().first;
		j0 = qq.front().second;
		qq.pop();
		for(i = -1; i <= 1; i++){
			for(j = -1; j <= 1; j++){
				if (abs(i) + abs(j) != 1)
					continue;
				i1 = i + i0;
				j1 = j + j0;
				if (c[i1][j1] ==' Y')
					continue;
				t = tt1[i0][j0] + 1;
				if (t == tt[i1][j1]){
					for(k1 = 0; k1 < (int)v[0][i00][j00].size(); k1++){
						int s = v[0][i00][j00][k1];
						for(k2 = 0; k2 < (int)v[1][i1][j1].size(); k2++){
							int to = v[1][i1][j1][k2];
							g[s][to] = 1;
						}
					}
				}
				if (t >= tt[i1][j1])
					continue;
				if (tt1[i1][j1] == -1){
					tt1[i1][j1] = t;
					qq.push(mp(i1, j1));
				}
			}
		}
	}
	int s, to;
	for(k1 = 0; k1 < (int)v[0][i00][j00].size(); k1++){
		s = v[0][i00][j00][k1];
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if (tt1[i][j] == -1)
					continue;
				for(k2 = 0; k2 < (int)v[1][i][j].size(); k2++){
					to = v[1][i][j][k2];
					g[s][to] = 1;
				}
			}
		}
	}
}

int try_kuhn(int s){
	if (used[s])
		return 0;
	used[s] = 1;
	for(int j = 1; j <= nn[1]; j++){
		if (!g[s][j])
			continue;
		if (!mt[j] || try_kuhn(mt[j])){
			mt[j] = s;
			return 1;
		}
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int i, j, k, l, t;
	scanf("%d %d", &n, &t);
	for(k = 0; k < 2; k++){
		for(i = 0; i < 15; i++){
			for(j = 0; j < 15; j++){
				c[i][j] = 'Y';
			}
		}
		for(i = 1; i <= n; i++){
			scanf("%s", &c[i][1]);
			c[i][n + 1] = 'Y';
		}
		nn[k] = 0;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if (c[i][j] >= '0' && c[i][j] <= '9'){
					for(l = '0'; l < c[i][j]; l++){
						v[k][i][j].pb(++nn[k]);
					}
				}
			}
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if (c[i][j] >= '0' && c[i][j] <= '9'){
				tt[i][j] = t;
			}
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if (c[i][j] == 'Z'){
				tt[i][j] = 0;
				c[i][j] = 'Y';
				set_tt(i, j);		
			}
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			go(i, j);
		}
	}
	int ans = 0;
	/*for(i = 1; i <= nn[0]; i++){
		for(j = 1; j <= nn[1]; j++){
			if (g[i][j] && !mt[j]){
				used[i] = 1;
				mt[j] = i;
				ans++;
				break;
			}
		}
	}*/
	for(i = 1; i <= nn[0]; i++){
		for(j = 1; j <= nn[0]; j++){
			used[j] = 0;
		}
		ans += try_kuhn(i);
	}
	printf("%d", ans);
}