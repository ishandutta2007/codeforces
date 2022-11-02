#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main() {
	int n, t;
	vector <vector <int> > res(2001, vector <int> (2001));
	scanf("%d %d", &n, &t);
	queue <pair <int, int> > q;
	q.push(make_pair(1000, 1000));
	res[1000][1000] = n;
	while(!q.empty()) {
		pair <int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		if(res[x][y] >= 4) {
			int plus = res[x][y] / 4;
			res[x][y] %= 4;
			res[x + 1][y] += plus;
			q.push(make_pair(x + 1, y));
			res[x - 1][y] += plus;
			q.push(make_pair(x - 1, y));
			res[x][y + 1] += plus;
			q.push(make_pair(x, y + 1));
			res[x][y - 1] += plus;
			q.push(make_pair(x, y - 1));
		}
	}
	for(int i = 0; i < t; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x += 1000;
		y += 1000;
		if(0 <= x && x <= 2000 && 0 <= y && y <= 2000) {
			printf("%d\n", res[x][y]);
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}