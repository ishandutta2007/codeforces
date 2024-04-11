#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int A[110], B[110];
vector<pair<int, int> > p;
vector<int> perm;

int main(){
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d%d", &A[i], &B[i]);

  p.clear();
  for(int i = 1; i <= N; i++) p.push_back(make_pair(-A[i], i));
  sort(p.begin(), p.end());

  for(int i = 0; i < N; i++){
    if(B[p[i].second] <= 0) perm.push_back(p[i].second);
  }
  for(int i = N - 1; i >= 0; i--){
    if(B[p[i].second] > 0) perm.push_back(p[i].second);
  }

  int res = 0;

  for(int i = 0; i < N; i++){
    int ni = perm[i];

    int oldi = -1, newi = -1;
    for(int j = 0; j < N; j++){
      if(p[j].second == ni){ oldi = j; p[j].first -= B[ni]; }
    }
    sort(p.begin(), p.end());
    for(int j = 0; j < N; j++) if(p[j].second == ni) newi = j;

    res += abs(oldi - newi);
  }

  printf("%d\n", res);
  return 0;
}