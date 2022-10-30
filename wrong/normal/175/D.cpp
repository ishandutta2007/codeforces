#include<cstdio>
#include<algorithm>

using namespace std;

double dp[201][201][64];
int turn[64];

int gcd(int m, int n)
{
  return n ? gcd(n, m % n) : m;
}

int lcm(int m, int n)
{
  return m / gcd(m, n) * n;
}

int main()
{
  int h[2], d[2], l[2], r[2], p[2];
  for(int i=0; i<2; ++i)
    scanf("%d%d%d%d%d", &h[i], &d[i], &l[i], &r[i], &p[i]);
  if(p[0] == 100) {
    puts("0");
    return 0;
  }
  if(p[1] == 100) {
    puts("1");
    return 0;
  }
  int ts = 0, tt = lcm(d[0], d[1]);
  for(int t=0; t<tt; ++t) {
    if(t % d[0] == 0) turn[ts++] = 0;
    if(t % d[1] == 0) turn[ts++] = 1;
  }
  double e[2];
  e[0] = 1.0 / (r[0] - l[0] + 1);
  e[1] = 1.0 / (r[1] - l[1] + 1);
  double same = 1;
  for(int t=0; t<ts; ++t)
    same *= p[turn[t]] / 100.0;
  for(int h1=1; h1<=h[0]; ++h1) {
    for(int h2=1; h2<=h[1]; ++h2) {
      for(int t=0; t<ts; ++t) {
	if(turn[t] == 0) {
	  int dmg_limit = min(r[0], h2 - 1), nt = (t+1) % ts;
	  dp[h1][h2][t] = 0;
	  for(int d=l[0]; d<=dmg_limit; ++d)
	    dp[h1][h2][t] += e[0] * dp[h1][h2-d][nt];
	  dp[h1][h2][t] += e[0] * min(r[0]-l[0]+1, r[0]-dmg_limit);
	  dp[h1][h2][t] *= (100 - p[0]) / 100.0;
	} else {
	  int dmg_limit = min(r[1], h1 - 1), nt = (t+1) % ts;
	  dp[h1][h2][t] = 0;
	  for(int d=l[1]; d<=dmg_limit; ++d)
	    dp[h1][h2][t] += e[1] * dp[h1-d][h2][nt];
	  dp[h1][h2][t] *= (100 - p[1]) / 100.0;
	}
      }
      double prod = 1;
      for(int t=1; t<ts; ++t) {
	prod *= (turn[t-1] ? p[1] : p[0]) / 100.0;
	dp[h1][h2][0] += prod * dp[h1][h2][t];
      }
      dp[h1][h2][ts] = (dp[h1][h2][0] /= 1 - same);
      for(int t=ts-1; t>0; --t)
	dp[h1][h2][t] += (turn[t] ? p[1] : p[0]) / 100.0 * dp[h1][h2][t+1];
    }
  }
  printf("%.9f\n", dp[h[0]][h[1]][0]);
  return 0;
}