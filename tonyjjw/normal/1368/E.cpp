#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 2e5;
int TC, N, M;
vector<int> E[MN];
bool dead[MN];
bool killson[MN];

int main() {
  scanf("%d", &TC);
  for(int tc = 1; tc <= TC; tc++) {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
      E[i].clear();
      dead[i] = false;
      killson[i] = false;
    }
    for(int i = 0; i < M; i++) {
      int a, b;
      scanf("%d%d", &a, &b); a--, b--;
      E[a].push_back(b);
    }
    for(int i = 0; i < N; i++)
      sort(E[i].begin(), E[i].end());
    for(int i = 0; i < N; i++) {
      if (dead[i]) continue;
      if (killson[i]) {
        for(auto &j: E[i]) {
          dead[j] = true;
        }
      }
      else {
        for(auto &j: E[i]) {
          killson[j] = true;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
      if (dead[i]) ans++;
    }
    printf("%d\n", ans);
    for(int i = 0; i < N; i++) {
      if (dead[i]) printf("%d ", i+1);
    }
    puts("");
  }
  return 0;
}