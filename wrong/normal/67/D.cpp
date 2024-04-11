#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int x[1<<20], y[1<<20], p[1<<20];
vector<int> q;
const int inf = 99999999;
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
int lis_fast(const vector<int>& a) {
  const int n = a.size();
  vector<int> A(n, inf);
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    id[i] = index_of(A, a[i]);
    A[ id[i] ] = a[i];
  }
  return *max_element(id.begin(), id.end()) + 1;
}
int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d", &x[i]);
    p[x[i]] = i;
  }
  q.resize(n);
  for(int i=0; i<n; ++i) {
    scanf("%d", &y[i]);
    q[p[y[i]]] = -i;
  }
  printf("%d\n", lis_fast(q));
  return 0;
}