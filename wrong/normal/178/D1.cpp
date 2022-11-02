#include<cstdio>
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

struct part {
  int t[4];
  int idx;
};

int SS, use[16];
int sum[6];
vector<part> P;
int n, a[16];

void dfs(int p, int u)
{
  if(p == 16) {
    if(ismagic(n, use)) {
      printf("%d\n", SS);
      for(int i=0; i<n; ++i)
	for(int j=0; j<n; ++j)
	  printf("%d%c", use[i*n+j], j==n-1?'\n':' ');
      exit(0);
    }
    return;
  }
  if(p % 4 == 3) {
    int s = use[p-1]+use[p-2]+use[p-3];
    for(int i=0; i<16; ++i) {
      if((u & (1<<i)) == 0) {
	if(s + a[i] == SS) {
	  bool cond = true;
	  if(p == 15) {
	    int t = use[0] + use[5] + use[10] + a[i];
	    cond &= t == SS;
	    int x = use[3] + use[7] + use[11] + a[i];
	    cond &= x == SS;
	  }
	  use[p] = a[i];
	  if(cond) dfs(p+1, u|(1<<i));
	}
      }
    }
    return;
  }
  if(p / 4 == 3) {
    int s = use[p-4]+use[p-8]+use[p-12];
    for(int i=0; i<16; ++i) {
      if((u & (1<<i)) == 0) {
	if(s + a[i] == SS) {
	  bool cond = true;
	  if(p == 12) {
	    int t = use[3] + use[6] + use[9] + a[i];
	    cond &= t == SS;
	  }
	  use[p] = a[i];
	  if(cond) dfs(p+1, u|(1<<i));
	}
      }
    }
    return;
  }
  for(int i=0; i<16; ++i) {
    if((u & (1<<i)) == 0) {
      use[p] = a[i];
      dfs(p+1, u|(1<<i));
    }
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
    for(int i=0; i<n*n; ++i)
      SS += a[i];
    SS /= n;
    dfs(0, 0);
  }

  return 0;
}