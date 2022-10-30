#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int A[100050], B[100050];

int main()
{
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for(int i=0; i<n; ++i)
    scanf("%d", &A[i]);
  for(int i=0; i<m; ++i)
    scanf("%d", &B[i]);

  int ai = 0;
  vector<pair<int, int> > sol;
  for(int bi=0; bi<m; ++bi) {
    while(ai<n && B[bi]>A[ai]+y) ai++;
    if(ai<n && A[ai]-x <= B[bi] && B[bi] <= A[ai]+y) {
      sol.push_back(make_pair(ai+1, bi+1));
      ai++;
    }
  }

  printf("%d\n", sol.size());
  for(int i=0; i<(int)sol.size(); ++i)
    printf("%d %d\n", sol[i].first, sol[i].second);

  return 0;
}