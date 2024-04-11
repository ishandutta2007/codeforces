#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, A[N][N];
int dis[4][N][N];

char s[N][N];

deque < pair <int, int> > q;

#define mp make_pair
#define pii pair <int, int>

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(pii who, int x) {
  if(who.first < 1 || who.first > n || who.second < 1 || who.second > m) return 0;
  if(s[who.first][who.second] == '#') return 0;
  if(dis[x][who.first][who.second] != -1) return 0;
  return 1;
}

void solve(int x) {
  while(!q.empty()) q.pop_back();
  memset(dis[x], -1, sizeof(dis[x]));
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j)
      if(s[i][j] == x + '0')
	q.push_back(make_pair(i, j)), dis[x][i][j] = 0; 
  }
  while(!q.empty()) {
    pii ind = q.front();
    q.pop_front();
    //cerr << x <<" " <<  ind.first << " " << ind.second <<" " << dis[x][ind.first][ind.second] << endl;
    for(int i = 0; i < 4; ++ i) {
      pii who = ind;
      who.first += dx[i], who.second += dy[i];
      if(!valid(who, x)) continue;
      if(s[who.first][who.second] != '.') {
	q.push_front(who);
	dis[x][who.first][who.second] = dis[x][ind.first][ind.second];
      }
      else {
	q.push_back(who);
	dis[x][who.first][who.second] = dis[x][ind.first][ind.second] + 1;
      }
    }
  }
}

int x[4], y[4];

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    scanf("%s", s[i] + 1);
  }
  for(int i = 1; i <= 3; ++ i) {
    solve(i);
  }
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j)
      if(s[i][j] != '#' && s[i][j] != '.') {
	x[s[i][j] - '0'] = i;
	y[s[i][j] - '0'] = j;
      }
  }
  int ans = 1e9;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j) {
      bool ok = 1;
      for(int a = 1; a <= 3; ++ a)
	if(dis[a][i][j] == -1) ok = 0;
      if(!ok) continue;
      int res = 0;
      for(int a = 1; a <= 3; ++ a)
	res += dis[a][i][j];
      if(s[i][j] == '.') res -= 2;
      ans = min(ans, res);
    }
  }

  if(ans > 1e8) {
    puts("-1");
    return 0;
  }

  for(int a = 1; a <= 3; ++ a) {
    int res = 0;
    for(int b = 1; b <= 3; ++ b) if(a != b) {
	res += dis[a][x[b]][y[b]];
      }
    ans = min(ans, res);
  }
  
  if(ans > 1e8) cout << -1 << endl;
  else cout << ans << endl;
}