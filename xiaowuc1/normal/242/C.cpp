#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main() {
  int sx,sy,ex,ey;
  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
  map<pair<int, int>, int> dist;
  int n;
  scanf("%d", &n);
  while(n-- > 0) {
    int r, a, b;
    scanf("%d%d%d", &r, &a, &b);
    for(int k = a; k <= b; k++) {
      pair<int, int> pt = make_pair(r, k);
      dist.insert(make_pair(pt, 1 << 25));
    }
  }
  queue<pair<int, int> > q;
  q.push(make_pair(sx,sy));
  dist[make_pair(sx,sy)] = 0;
  while(!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    for(int k = 0; k < 8; k++) {
      pair<int, int> next = make_pair(curr.first + dx[k], curr.second + dy[k]);
      if(dist.count(next) == 1) {
	if(1 + dist[curr] < dist[next]) {
	  dist[next] = 1 + dist[curr];
	  q.push(next);
	}
      }
    }
  }
  if(dist[make_pair(ex,ey)] == 1<<25) {
    dist[make_pair(ex,ey)] = -1;
  }
  printf("%d\n", dist[make_pair(ex,ey)]);
}