#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

struct mart{
  int c, k, p;
  mart(int c, int k, int p) : c(c), k(k), p(p) {}
  bool operator< (const mart& rhs) const {
    return p < rhs.p;
  }
};

vector<int> con[5010];
vector<mart> ms;

int dist[5010][5010]; // [city][mart]
queue<pair<int, int> > q;

int main(){
  int N, M; scanf("%d%d", &N, &M);
  for(int i = 0; i < M; i++){
    int x, y; scanf("%d%d", &x, &y);
    con[x].push_back(y); con[y].push_back(x);
  }
  int MC; scanf("%d", &MC);
  for(int i = 0; i < MC; i++){
    int c, k, p; scanf("%d%d%d", &c, &k, &p);
    ms.push_back(mart(c, k, p));
  }

  sort(ms.begin(), ms.end());

  // get distance
  for(int i = 0; i < MC; i++){
    for(int j = 1; j <= N; j++) dist[j][i] = INF;

    int sx = ms[i].c;
    dist[sx][i] = 0; q.push(make_pair(sx, 0));
    while(!q.empty()){
      int x = q.front().first, d = q.front().second; q.pop();
      for(int nx : con[x]){
        if(dist[nx][i] == INF){
          dist[nx][i] = d + 1; q.push(make_pair(nx, d + 1));
        }
      }
    }
  }

  int QC; scanf("%d", &QC);
  for(; QC--; ){
    int G, R, A; scanf("%d%d%d", &G, &R, &A);

    int ans = -1;
    int rs = 0, re = N - 1;

    for(; rs <= re; ){
      int rm = (rs + re) / 2;

      long long tot = 0; int rem = R;
      for(int i = 0; rem > 0 && i < MC; i++){
        if(dist[G][i] <= rm){
          if(ms[i].k >= rem){ tot += (long long)rem * ms[i].p; rem = 0; }
          else{ tot += (long long)ms[i].k * ms[i].p; rem -= ms[i].k; }
        }
      }

      if(rem == 0 && tot <= A){ // valid
        ans = rm; re = rm - 1;
      }
      else rs = rm + 1;
    }

    printf("%d\n", ans);
  }
  return 0;
}