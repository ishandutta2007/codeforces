#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, m;
char tbl[1024][1024];

bool v[2048];
vector<int> row[1024];
vector<int> col[1024];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; ++i) {
    scanf("%s", tbl[i]);
    for(int j=0; j<m; ++j)
      if(tbl[i][j] == '#')
	row[i].push_back(j), col[j].push_back(i);
  }

  queue<pair<int, int> > q;
  q.push(make_pair(n-1, 0));
  v[n-1] = true;
  while(!q.empty()) {
    int u = q.front().first, c = q.front().second; q.pop();
    if(u == 0) { printf("%d\n", c); return 0; }
    if(u < n) {
      for(int i=0; i<(int)row[u].size(); ++i)
	if(!v[n+row[u][i]])
	  q.push(make_pair(n+row[u][i], c+1)), v[n+row[u][i]]=true;
    }
    if(u >= n) {
      u -= n;
      for(int i=0; i<(int)col[u].size(); ++i)
	if(!v[col[u][i]])
	  q.push(make_pair(col[u][i], c+1)), v[col[u][i]]=true;
    }
  }
  puts("-1");
  return 0;
}