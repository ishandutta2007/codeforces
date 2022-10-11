#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int n;
bool can[1005][1005];

int main() {
  scanf("%d", &n);
  int ax, ay, bx, by, cx, cy;
  scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
  can[bx][by] = true;
  queue<pii> q;
  q.push(pii(bx, by));
  while(!q.empty()) {
    pii curr = q.front();
    q.pop();
    for(int dx = -1; dx <= 1; dx++) {
      for(int dy = -1; dy <= 1; dy++) {
        int nx = curr.first + dx;
        int ny = curr.second + dy;
        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if(ax == nx) continue;
        if(ay == ny) continue;
        if(ax-ay == nx-ny) continue;
        if(ax+ay == nx+ny) continue;
        if(can[nx][ny]) continue;
        can[nx][ny] = true;
        q.push(pii(nx, ny));
      }
    }
  }
  if(can[cx][cy]) printf("YES\n");
  else printf("NO\n");
}