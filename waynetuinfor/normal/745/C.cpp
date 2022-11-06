#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <algorithm>
#define int long long
using namespace std;

const int MAXN = 1000 + 5;
int n, m, k, c[MAXN], a, b, cc, edge, st[MAXN], Max, uncut, uc;
bool cut[MAXN];
bitset<MAXN> v;
set<int> gov;
vector<int> G[MAXN], CC[MAXN];
void DFS(int);
bool cmp(const int&, const int&);

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) cin >> c[i], gov.insert(c[i]);
  for (int _ = 0; _ < m; ++_) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!v[i]) cc++, DFS(i);
  }
  for (int i = 1; i <= cc; ++i) st[i] = i;
  // sort(st + 1, st + cc + 1, cmp);
  for (int i = 1; i <= cc; ++i) {
    if (cut[i]) Max = max(Max, (int)CC[i].size());
    else uncut += (int)CC[i].size();
  }
  edge += Max * uncut;
  for (int i = 1; i <= cc; ++i) if (!cut[i]) uc += (int)CC[i].size() * (uncut - (int)(CC[i].size()));
  edge += (uc / 2);
  for (int i = 1; i <= cc; ++i) edge += (int)(CC[i].size()) * (int)(CC[i].size() - 1) / 2;
  cout << edge - m << '\n';
  return 0;
}

void DFS(int x) {
  if (gov.count(x)) cut[cc] = true;
  v[x] = true;
  CC[cc].push_back(x);
  for (int u : G[x]) if (!v[u]) DFS(u);
}

bool cmp(const int& a, const int& b) {
  return CC[a].size() > CC[b].size();
}