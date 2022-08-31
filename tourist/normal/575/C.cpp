#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

int friday[42][42];
int saturday[42][42];
int ans;
int n;
int a[42][42];
int u[42], v[42], p[42], way[42];
int minv[42];
bool used[42];

void dfs(int i, int fridays, int saturdays) {
  if (i == n + 1) {
    ans = max(ans, v[0]);
    return;
  }
  int old_u[21], old_v[21], old_p[21], old_way[21];
  for (int rot = 0; rot < 2; rot++) {
    if (rot == 0 && fridays == n / 2) {
      continue;
    }
    if (rot == 1 && saturdays == n / 2) {
      continue;
    }
    for (int j = 0; j < n; j++) {
      a[i][j + 1] = -(rot == 0 ? friday[i - 1][j] : saturday[i - 1][j]);
    }
  	for (int j = 0; j <= n; j++) {
  	  old_u[j] = u[j];
  	  old_v[j] = v[j];
  	  old_p[j] = p[j];
  	  old_way[j] = way[j];
  	}
  	p[0] = i;
  	int j0 = 0;
  	for (int j = 0; j <= n; j++) {
  	  minv[j] = INF;
  	  used[j] = false;
  	}
  	do {
  		used[j0] = true;
  		int i0 = p[j0],  delta = INF,  j1;
  		for (int j=1; j<=n; ++j)
  			if (!used[j]) {
  				int cur = a[i0][j]-u[i0]-v[j];
  				if (cur < minv[j])
  					minv[j] = cur,  way[j] = j0;
  				if (minv[j] < delta)
  					delta = minv[j],  j1 = j;
  			}
  		for (int j=0; j<=n; ++j)
  			if (used[j])
  				u[p[j]] += delta,  v[j] -= delta;
  			else
  				minv[j] -= delta;
  		j0 = j1;
  	} while (p[j0] != 0);
  	do {
  		int j1 = way[j0];
  		p[j0] = p[j1];
  		j0 = j1;
  	} while (j0);
  	dfs(i + 1, fridays + (rot == 0), saturdays + (rot == 1));
  	for (int j = 0; j <= n; j++) {
  	  u[j] = old_u[j];
  	  v[j] = old_v[j];
  	  p[j] = old_p[j];
  	  way[j] = old_way[j];
  	}
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", friday[i] + j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", saturday[i] + j);
    }
  }
  for (int i = 0; i <= n; i++) {
    u[i] = v[i] = p[i] = way[i] = 0;
  }
  ans = 0;
  dfs(1, 0, 0);
  printf("%d\n", ans);
  return 0;
}