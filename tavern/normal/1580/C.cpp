#include <bits/stdc++.h>

using namespace std;

const int maxv = 2e5 + 5;
const int B = 350;

int n, m;
int x[maxv], y[maxv], f[B][maxv / B + 5], t[maxv], sum[maxv];

int main(){
  //freopen("C.in", "r", stdin);
  
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d%d", x + i, y + i);

  int tot = 0, s = 0;
  
  for(int i = 0; i < m; ++i){
    int tp, id;
    scanf("%d%d", &tp, &id); --id; 
    if(x[id] + y[id] < B){
      if(tp == 1)
	t[id] = i;
      int l = t[id] % (x[id] + y[id]), r = (t[id] + x[id]) % (x[id] + y[id]);
      for(int j = l; j != r; (++j) %= (x[id] + y[id]))
	f[x[id] + y[id]][j] += (tp == 1 ? 1 : -1);
    }
    else{
      if(tp == 1)
	t[id] = i;
      for(long long j = t[id]; j < maxv; j += x[id] + y[id]){
	int l = max((int)j, i), r = min((int)j + x[id], maxv - 1);
	if(l >= r)
	  continue;
	sum[l] += (tp == 1 ? 1 : -1);
	if(j + x[id] < maxv)
	  sum[r] += (tp == 1 ? -1 : 1);
      }
    }
    tot += (tp == 1 ? 1 : -1);
    s += sum[i];
    int ans = s;
    for(int j = 1; j < B; ++j)
      ans += f[j][i % j];
    printf("%d\n", tot - ans);
  }
  return 0;
}