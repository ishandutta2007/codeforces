#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int INF = 1e9;
const int hx[4] = {-1, 0, 0, 1};
const int hy[4] = {0, -1, 1, 0};

vector<vector<int> > go(const vector<string> &a, int x) {
	int n = (int)a.size();
	int m = (int)a[0].size();
	vector< vector<int> > dist(n, vector<int>(m));
	deque< pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = (a[i][j] - '0' == x ? 0 : INF);
			if (dist[i][j] == 0) {
				q.push_back(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int cx = x + hx[i];
			int cy = y + hy[i];
			if ((cx < 0) || (cy < 0) || (cx >= n) || (cy >= m)) continue;
			if (a[cx][cy] == '#') continue;
			int cost = a[cx][cy] == '.';
			if (dist[x][y] + cost < dist[cx][cy]) {
				dist[cx][cy] = dist[x][y] + cost;
				if (cost == 0) {
					q.push_front(make_pair(cx, cy));					
				} else {
					q.push_back(make_pair(cx, cy));
				}
			}
		}
	}
	return dist;
}

int main() {
	// freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d%d\n", &n, &m);
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector< vector< vector<int> > > dist(3);
	dist[0] = go(a, 1);
	dist[1] = go(a, 2);
	dist[2] = go(a, 3);
	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int csum = 0;
			bool is0 = false;
			for (int k = 0; k < 3; k++) {
				is0 |= (dist[k][i][j] == 0);
				if (dist[k][i][j] == INF) {
					csum = INF;
					break;
				} else csum += dist[k][i][j];
			}
			if (csum == INF) continue;
			if (!is0) csum -= 2; 
			ans = min(ans, csum);
		}
	}
	printf("%d\n", ans == INF ? -1 : ans);
}