#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct domino {
  int x, h, id, xi, z;
  domino(int x=0) : x(x), z(0) { }
};

bool cmp_x(const domino& a, const domino& b) {
  return a.x < b.x;
}
bool cmp_i(const domino& a, const domino& b) {
  return a.id < b.id;
}

int main()
{
  int n, m = 320;
  scanf("%d", &n);

  vector<domino> d(n);
  for(int i=0; i<n; ++i) {
    d[i].id = i;
    scanf("%d%d", &d[i].x, &d[i].h);
  }
  sort(d.begin(), d.end(), cmp_x);

  vector<int> b(n/m+1, 0);
  for(int i=n-1; i>=0; --i) {
    int p = lower_bound(d.begin(), d.end(), domino(d[i].x+d[i].h), cmp_x) - d.begin() - 1;
    for(int j=i+1; j<=p && j%m!=0; ++j) d[i].z = max(d[i].z, d[j].z);
    if(i/m != p/m) {
      for(int j=i/m+1; j*m+m<=p; ++j) d[i].z = max(d[i].z, b[j]);
      for(int j=p/m*m; j<=p; ++j) d[i].z = max(d[i].z, d[j].z);
    }
    if(i == p) d[i].z = i+1;
    b[i/m] = max(b[i/m], d[i].z);
    d[i].xi = i;
  }

  sort(d.begin(), d.end(), cmp_i);
  for(int i=0; i<n; ++i)
    printf("%d%c", d[i].z-d[i].xi, i==n-1?'\n':' ');

  return 0;
}