#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool ismagic(int n, int *a)
{
  int S = 0;
  for(int i=0; i<n*n; ++i) S += a[i];
  if(S % n != 0) return false;
  S /= n;

  for(int i=0; i<n; ++i) {
    int s = 0;
    for(int j=0; j<n; ++j)
      s += a[i*n+j];
    if(s != S) return false;
    s = 0;
    for(int j=0; j<n; ++j)
      s += a[j*n+i];
    if(s != S) return false;
  }

  int s = 0;
  for(int i=0; i<n; ++i)
    s += a[i*n+i];
  if(s != S) return false;

  s = 0;
  for(int i=0; i<n; ++i)
    s += a[i*n+n-i-1];
  if(s != S) return false;

  return true;
}

int SS, use[16];
int sum[6];
int n, a[16];

map<int, vector<pair<int, int> > > U;
int search_order[][2] = {
  {0, 15}, {3, 12}, {0, 3}, {12, 15}, {0, 12}, {3, 15}
};

void dfs(int p, int u)
{
  int A = search_order[p][0], B = search_order[p][1];
  int C = (B - A) / 3;

  vector<pair<int, int> >& e = U[use[A]+use[B]];
  for(int i=0; i<(int)e.size(); ++i) {
    use[A+C] = a[e[i].first];
    use[B-C] = a[e[i].second];
    if((u & (1<<e[i].first)) || (u & (1<<e[i].second))) continue;
    if(p == 3 && use[1]+use[5]+use[9]+use[13]!=SS) continue;
    if(p == 5) {
      if(use[4]+use[5]+use[6]+use[7] == SS) {
	printf("%d\n", SS);
	for(int j=0; j<n; ++j)
	  for(int k=0; k<n; ++k)
	    printf("%d%c", use[j*n+k], k==n-1?'\n':' ');
	exit(0);
      }
      continue;
    } else dfs(p+1, u|(1<<e[i].first)|(1<<e[i].second));
  }
}

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n*n; ++i)
    scanf("%d", &a[i]);

  if(n <= 3) {
    sort(a, a+n*n);
    do {
      if(ismagic(n, a)) {
	int S = 0;
	for(int i=0; i<n*n; ++i)
	  S += a[i];
	printf("%d\n", S/n);
	for(int i=0; i<n; ++i)
	  for(int j=0; j<n; ++j)
	    printf("%d%c", a[i*n+j], j==n-1?'\n':' ');
	return 0;
      }
    } while(next_permutation(a, a+n*n));
  } else {
    SS = 0;
    sort(a, a+16);
    for(int i=0; i<n*n; ++i)
      SS += a[i];
    SS /= n;
    for(int i=0; i<n*n; ++i) {
      for(int j=i+1; j<n*n; ++j) {
	U[SS-a[i]-a[j]].push_back(make_pair(i, j));
	U[SS-a[i]-a[j]].push_back(make_pair(j, i));
      }
    }
    for(int i=0; i<n*n; ++i) {
      for(int j=0; j<n*n; ++j) {
	if(i==j) continue;
	for(int k=0; k<n*n; ++k) {
	  if(i==k||j==k) continue;
	  int rem = 0;
	  while(rem<n*n) {
	    if(i==rem||j==rem||k==rem) {rem++;continue;}
	    if(a[i]+a[j]+a[k]+a[rem]==SS) break;
	    rem++;
	  }
	  if(rem>=n*n) continue;
	  use[0] = a[i];
	  use[3] = a[j];
	  use[12] = a[k];
	  use[15] = a[rem];
	  dfs(0, (1<<i)|(1<<j)|(1<<k)|(1<<rem));
	}
      }
    }
  }

  return 0;
}