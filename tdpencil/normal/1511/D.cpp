#include <bits/stdc++.h>
 
using namespace std;
 
int n, k;
vector<int> cur(26);
vector<int> path;
 
void dfs(int v) {
  while (cur[v] < k) {
    int u = cur[v]++;
    dfs(u);
    path.push_back(u);
  }
}
 
int main() {
  scanf("%d%d", &n, &k);
  dfs(0);
  printf("a");
  for (int i = 0; i < n - 1; ++i)
    printf("%c", path[i % path.size()] + 'a');
}