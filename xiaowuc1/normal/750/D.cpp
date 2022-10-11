#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;

int n;
int l[35];

bool dp[400][400][31][8];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct state {
  int x, y, i, d;
};

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  queue<state> q;
  q.push(state{200, 200, 0, 1});
  set<pii> s;
  while(!q.empty()) {
    state curr = q.front();
    q.pop();
    for(int a = 1; a <= l[curr.i]; a++) {
      s.insert(pii(curr.x + a * dx[curr.d], curr.y + a * dy[curr.d]));
    }
    if(curr.i + 1 == n) {
      continue;
    }
    int nx = curr.x + l[curr.i] * dx[curr.d];
    int ny = curr.y + l[curr.i] * dy[curr.d];
    if(!dp[nx][ny][curr.i+1][(curr.d+1)%8]) {
      dp[nx][ny][curr.i+1][(curr.d+1)%8] = true;
      q.push(state{nx, ny, curr.i+1, (curr.d+1)%8});
    }
    if(!dp[nx][ny][curr.i+1][(curr.d+7)%8]) {
      dp[nx][ny][curr.i+1][(curr.d+7)%8] = true;
      q.push(state{nx, ny, curr.i+1, (curr.d+7)%8});
    }
  }
  printf("%d\n", s.size());
}