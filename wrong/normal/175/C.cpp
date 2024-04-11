#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

struct figures {
  ll k, c;
} F[128];
bool operator < (const figures& a, const figures& b)
{
  return a.c < b.c;
}

int main()
{
  int n, t;
  ll p[128], S = 0;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%I64d%I64d", &F[i].k, &F[i].c), S += F[i].k;
  sort(F, F+n);
  scanf("%d", &t);
  for(int i=0; i<t; ++i)
    scanf("%I64d", &p[i]);
  p[t] = S + 1;
  ll destroyed = 0, f = 1, sol = 0;
  for(int i=0; i<n; ++i) {
    ll d = 0;
    while(d < F[i].k) {
      if(destroyed + F[i].k - d <= p[f-1]) {
	destroyed += F[i].k - d;
	sol += (F[i].k - d) * f * F[i].c;
	d = F[i].k;
	if(destroyed == p[f-1])
	  f++;
      } else {
	sol += (p[f-1] - destroyed) * f * F[i].c;
	d += p[f-1] - destroyed;
	destroyed = p[f-1];
	f++;
      }
    }
  }
  printf("%I64d\n", sol);
  return 0;
}