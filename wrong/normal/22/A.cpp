#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  int n;
  vector<int> s;
  scanf("%d", &n);
  s.resize(n);
  for(int i=0; i<n; ++i) scanf("%d", &s[i]);
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  if(s.size()<=1) puts("NO"); else printf("%d\n", s[1]);
  return 0;
}