#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

char F[2048][2048];

char V[2048][2048];
int M[4096];

#define mp(a, b) make_pair(a, b)

static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

vector<int> xs, ys;

int bfs(int x, int y, int cx = -1, int cy = -1, int vv = 0)
{
  int cnt = 1;
  queue<pair<int, int> > q;
  if(cx >= 0) memset(M, 0, sizeof(M));
  q.push(mp(x, y));
  V[y][x] = vv + 1;
  xs.push_back(x);
  ys.push_back(y);
  while(!q.empty()) {
    int c = q.front().first, r = q.front().second;
    q.pop();
    for(int i=0; i<4; ++i) {
      int rr = r+dy[i], cc = c+dx[i];
      if(F[rr][cc] == 1 && V[rr][cc] <= vv) {
	V[rr][cc] = vv + 1;
	q.push(mp(cc, rr));
	cnt++;
	if(cx >= 0) {
	  int dis = sqrt((rr-cy)*(rr-cy)+(cc-cx)*(cc-cx))+0.5;
	  M[dis]++;
	}
	xs.push_back(cc);
	ys.push_back(rr);
      }
    }
  }
  return cnt;
}

int main()
{
  int n;
  scanf("%d", &n);

  memset(F, 0, sizeof(F));
  for(int i=2; i<=n+1; ++i) {
    for(int j=2; j<=n+1; ++j) {
      int t;
      scanf("%d", &t);
      F[i][j] = t;
    }
  }

  for(int i=2; i<=n+1; ++i) {
    for(int j=2; j<=n+1; ++j) {
      int S = 0;
      for(int y=i-1; y<=i+1; ++y)
	for(int x=j-1; x<=j+1; ++x)
	  S += F[y][x];
      F[i][j] = S / 5;
    }
  }

  int sq = 0, ci = 0;

  for(int i=2; i<=n+1; ++i) {
    for(int j=2; j<=n+1; ++j) {
      if(F[i][j] == 0 || V[i][j]) continue;
      xs.clear(); ys.clear();
      if(bfs(j, i) >= 100) {
	int m = xs.size();
	long long cx = 0, cy = 0;
	for(int k=0; k<m; ++k) {
	  cx += xs[k];
	  cy += ys[k];
	}
	bfs(j, i, (cx+m/2) / m, (cy+m/2) / m, 1);
	int maxd = 0;
	for(int k=4095; k>=0; --k) {
	  if(M[k]) {
	    maxd = k;
	    break;
	  }
	}
	int most = max_element(M, M+maxd+1) - M;
	if(most >= maxd * 0.80) ci++;
	else sq++;
      }
    }
  }

  printf("%d %d\n", ci, sq);
  return 0;
}