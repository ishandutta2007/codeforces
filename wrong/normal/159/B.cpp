#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void solve(const vector<int>& m, const vector<int>& c, int& u, int& v)
{
  map<int, int> mx;
  for(int i=0; i<(int)m.size(); ++i)
    mx[m[i]]++;

  u += min(m.size(), c.size());
  for(int i=0; i<(int)c.size(); ++i) {
    if(mx[c[i]] > 0) {
      v++;
      mx[c[i]]--;
    }
  }
}

int main()
{
  int n, m;
  vector<pair<int, int> > markers, caps;

  scanf("%d%d", &n, &m);
  markers.resize(n);
  caps.resize(m);
  for(int i=0; i<n; ++i)
    scanf("%d%d", &markers[i].second, &markers[i].first);
  for(int i=0; i<m; ++i)
    scanf("%d%d", &caps[i].second, &caps[i].first);

  sort(markers.begin(), markers.end());
  sort(caps.begin(), caps.end());

  int u = 0, v = 0, c = 0;
  for(int i=0, j; i<n; i=j) {
    vector<int> mx, cx;
    for(j=i; j<n && markers[i].first==markers[j].first; ++j)
      mx.push_back(markers[j].second);
    while(c<m && markers[i].first>caps[c].first)
      c++;
    for(; c<m && markers[i].first==caps[c].first; ++c)
      cx.push_back(caps[c].second);
    solve(mx, cx, u, v);
  }

  printf("%d %d\n", u, v);
  return 0;
}