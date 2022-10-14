#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int n, m, a[105][105];
char s[105];
bool vis[105][105];
PII prv[105][105];

bool valid(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != -1;
}

void dfs(int x, int y)
{
	vis[x][y] = true;
	rep(d, 4) {
		int nx = x + dx[d], ny = y + dy[d];
		if(valid(nx, ny) && !vis[nx][ny]) {
 			prv[nx][ny] = MP(x, y);
		 	dfs(nx, ny);	
		}
	}
}

PII ask(char dir) 
{
	printf("%c\n", dir);
	fflush(stdout);
	PII ret;
	scanf("%d%d", &ret.first, &ret.second);
	assert(ret.first != -1);
	return ret;	
}

int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) {
		scanf("%s", s + 1);
		rep1(j, m) a[i][j] = (s[j] == '.' ? 0 : (s[j] == 'F' ? 1 : -1));
	}
	dfs(1, 1);
	int fx, fy;
	rep1(i, n) rep1(j, m) if(a[i][j] == 1) fx = i, fy = j;
	vector<PII> path;
	while(fx != 0 && fy != 0) {
		path.push_back(MP(fx, fy));
		PII c = prv[fx][fy];
		fx = c.first; fy = c.second;
	}
	reverse(path.begin(), path.end());
	bool cx, cy, wx, wy;
	cx = cy = wx = wy = false;
	rep(i, path.size() - 1) {
		if(path[i].first == path[i + 1].first) {
			if(cx) {
				ask(path[i].second > path[i + 1].second ? 'R' : 'L');
				continue;
			}
			if(wx) {
				ask(path[i].second > path[i + 1].second ? 'L' : 'R');
				continue;
			}
			wx = true;
			if(path[i].second < path[i + 1].second) {
				PII c = ask('R');
				if(c == path[i]) {
					cx = true;
					ask('L');
				}
			} else {
				PII c = ask('L');
				if(c == path[i]) {
					cx = true;
					ask('R');
				}
			}
		} else {
			if(cy) {
				ask(path[i].first > path[i + 1].first ? 'D' : 'U');
				continue;
			}
			if(wy) {
				ask(path[i].first > path[i + 1].first ? 'U' : 'D');
				continue;
			}
			wy = true;
			if(path[i].first < path[i + 1].first) {
				PII c = ask('D');
				if(c == path[i]) {
					cy = true;
					ask('U');
				}
			} else {
				PII c = ask('U');
				if(c == path[i]) {
					cy = true;
					ask('D');
				}
			}
			
		}
	}
	return 0;
}