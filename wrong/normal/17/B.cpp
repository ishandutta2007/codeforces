#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct emp {
  int q;
  vector<int> comes;
  vector<int> costs;
};
bool operator < (const emp& a, const emp& b)
{
  return a.q < b.q;
}

int main()
{
  int n;
  scanf("%d", &n);
  vector<emp> E(n);
  for(int i=0; i<n; ++i)
    scanf("%d", &E[i].q);
  int m;
  scanf("%d", &m);
  for(int i=0; i<m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--; b--;
    E[b].comes.push_back(a);
    E[b].costs.push_back(c);
  }
  sort(E.begin(), E.end());
  int sol = 0;
  int zero = 0;
  for(int i=0; i<E.size(); ++i) {
    if(E[i].comes.size() == 0) {
      zero++;
      continue;
    }
    int x = 1000000;
    for(int j=0; j<E[i].costs.size(); ++j)
      x = min(x, E[i].costs[j]);
    sol += x;
  }
  if(zero > 1) puts("-1");
  else printf("%d\n", sol);
  return 0;
}