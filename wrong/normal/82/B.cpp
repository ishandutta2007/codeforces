#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<set<int> > S, sol;
  for(int i=0; i<n*(n-1)/2; ++i) {
    int k, a;
    scanf("%d", &k);
    S.push_back(set<int>());
    for(int j=0; j<k; ++j) {
      scanf("%d", &a);
      S[i].insert(a);
    }
  }
  if(n == 2) {
    vector<int> N;
    for(set<int>::iterator it=S[0].begin(); it!=S[0].end(); ++it)
      N.push_back(*it);
    printf("1 %d\n", N[0]);
    printf("%d", N.size()-1);
    for(int i=1; i<(int)N.size(); ++i)
      printf(" %d", N[i]);
    puts("");
    return 0;
  }
  for(int i=1; sol.size()==0 && i<n*(n-1)/2; ++i) {
    set<int> x;
    for(set<int>::iterator it=S[i].begin(); it!=S[i].end(); ++it)
      if(S[0].count(*it)) x.insert(*it);
    if(x.size() > 0) {
      sol.push_back(x);
      break;
    }
  }
  for(int i=0; (int)sol.size()<n && i<n*(n-1)/2; ++i) {
    set<int> x;
    for(set<int>::iterator it=S[i].begin(); it!=S[i].end(); ++it)
      if(sol[0].count(*it) == 0) x.insert(*it);
    if(x.size() != S[i].size()) sol.push_back(x);
  }
  for(int i=0; i<n; ++i) {
    printf("%d", sol[i].size());
    for(set<int>::iterator it=sol[i].begin(); it!=sol[i].end(); ++it)
      printf(" %d", *it);
    puts("");
  }
  return 0;
}