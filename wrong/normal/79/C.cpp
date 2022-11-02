#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

char S[100050], B[10][16];
int main()
{
  int n, m, l[10];
  scanf("%s%d", S, &n);
  m = strlen(S);
  for(int i=0; i<n; ++i) {
    scanf("%s", B[i]);
    l[i] = strlen(B[i]);
  }
  vector<pair<int, int> > dame;
  for(int i=0; i<m; ++i) {
    for(int j=0; j<n; ++j) {
      if(i+l[j]>m) continue;
      if(strncmp(&S[i], B[j], l[j]) == 0)
	dame.push_back(make_pair(i, i+l[j]-1));
    }
  }
  dame.push_back(make_pair(m, m));
  sort(dame.begin(), dame.end());
  vector<int> min_end(dame.size());
  min_end.back() = dame.back().second;
  for(int i=(int)dame.size()-2; i>=0; --i)
    min_end[i] = min(min_end[i+1], dame[i].second);
  int len = -1, pos = -1;
  for(int i=0; i<m; ++i) {
    int p = lower_bound(dame.begin(), dame.end(), make_pair(i, -1)) - dame.begin();
    int q = max(0, min_end[p] - i);
    if(len < q) { len=q; pos=i; }
  }
  printf("%d %d\n", len, pos);
  return 0;
}