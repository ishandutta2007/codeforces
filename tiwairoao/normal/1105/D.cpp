#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1000;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
struct node{
	int x, y, d;
	node(int _x=0, int _y=0, int _d=0) : x(_x), y(_y), d(_d) {}
};
queue<node>q1, q2;
vector<node>v[10];
int ans[10], n, m, p;
int s[10], a[MAXN + 5][MAXN + 5];
char str[MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for(int i=1;i<=p;i++) scanf("%d", &s[i]);
	for(int i=1;i<=n;i++) {
		scanf("%s", str + 1);
		for(int j=1;j<=m;j++)
			if( str[j] == '#' ) a[i][j] = -1;
			else if( str[j] == '.' ) a[i][j] = 0;
			else v[a[i][j] = str[j] - '0'].push_back(node(i, j));
	}
	for(int i=1;i<=p;i++)
		for(int j=0;j<(int)v[i].size();j++)
			q1.push(node(v[i][j].x, v[i][j].y, i));
	while( !q1.empty() ) {
		int t = q1.front().d;
		while( !q1.empty() && q1.front().d == t ) {
			q2.push(node(q1.front().x, q1.front().y, s[t]));
			q1.pop();
		}
		while( !q2.empty() ) {
			node x = q2.front(); q2.pop(); ans[t]++;
			for(int i=0;i<4;i++) {
				int x0 = x.x + dx[i], y0 = x.y + dy[i];
				if( x0 < 1 || y0 < 1 || x0 > n || y0 > m || a[x0][y0] ) continue;
				a[x0][y0] = t;
				if( x.d == 1 ) q1.push(node(x0, y0, t));
				else q2.push(node(x0, y0, x.d - 1));
			}
		}
	}
	for(int i=1;i<=p;i++)
		printf("%d%c", ans[i], (i == p ? '\n' : ' '));
}