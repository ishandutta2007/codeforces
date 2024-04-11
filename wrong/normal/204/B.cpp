#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  
  map<int, int> all, front;
  for(int i=0; i<n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    all[a]++;
    if(a != b) all[b]++;
    front[a]++;
  }
  
  int res = 1<<20;
  for(map<int, int>::iterator it=all.begin(); it!=all.end(); ++it) {
    if(it->second >= (n+1)/2) {
      if(front[it->first] >= (n+1)/2) res = 0;
      else res = min(res, (n+1)/2 - front[it->first]);
    }
  }
  
  printf("%d\n", res==(1<<20) ? -1 : res);
  return 0;
}