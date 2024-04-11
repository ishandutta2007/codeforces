#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<algorithm>

using namespace std;

typedef long long ll;

int n, a, b, c;
int sx[3], sy[3];
ll t[4];

ll sum(ll a, ll b)
{
  if(a > b) swap(a, b);
  return (a+b)*(b-a+1)/2;
}

ll calc_cost(int x1, int y1, int x2, int y2, int x, int y)
{
  if(y1 == y2)
    return (ll)abs(y-y1)*(abs(x2-x1)+1)+sum(abs(x-x1), abs(x-x2));
  return (ll)abs(x-x1)*(abs(y2-y1)+1)+sum(abs(y-y1), abs(y-y2));
}

void go(int& x1, int& y1, int x2, int y2, ll* cost)
{
  assert(x1 == x2 || y1 == y2);
  if(x1 == x2) y1++; else x1++;
  for(int i=0; i<4; ++i)
    cost[i] += calc_cost(x1, y1, x2, y2, sx[i>>1], sy[i&1]);
  x1 = x2; y1 = y2;
}

bool bestroute(int x, int y)
{
  ll c1[4] = {0}, c2[4] = {0};
  int tx = x, ty = y;
  for(int i=0; i<3; ++i) {
    if(tx < sx[i]) go(tx, ty, sx[i], ty, c1);
    if(ty < sy[i]) go(tx, ty, tx, sy[i], c1);
  }
  tx = x; ty = y;
  for(int i=0; i<3; ++i) {
    if(i!=1) {
      if(tx < sx[i]) go(tx, ty, sx[i], ty, c2);
      if(ty < sy[i]) go(tx, ty, tx, sy[i], c2);
    } else {
      if(ty < sy[i]) go(tx, ty, tx, sy[i], c2);
      if(tx < sx[i]) go(tx, ty, sx[i], ty, c2);
    }
  }
  // printf("\n%lld %lld %lld %lld\n", c1[0], c1[1], c1[2], c1[3]);
  // printf("%lld %lld %lld %lld\n", c2[0], c2[1], c2[2], c2[3]);
  if(t[0] < c1[0] || t[3] < c1[3] || t[1] < c2[1] || t[2] < c1[2]) return false;
  assert(c1[1] >= c2[1]);
  assert(c2[2] >= c1[2]);
  ll M1 = max(c1[1], c2[1]), m1 = min(c1[1], c2[1]);
  ll M2 = max(c1[2], c2[2]), m2 = min(c1[2], c2[2]);
  ll ul = min(t[1], M1) - m1, dr = min(t[2], M2) - m2;
  if(ul % 2 == 1) --ul;
  if(dr % 2 == 1) --dr;
  // printf("%lld %lld\n", ul, dr);
  if(ul < 0 || dr < 0 || ul+dr < M1-m1) return false;
  return true;
}

void enter(int x, int y, int coef)
{
  for(int i=0; i<4; ++i)
    t[i] += (ll)coef * (abs(sx[i>>1]-x) + abs(sy[i&1]-y));
}

void print()
{
  for(int i=0; i<4; ++i)
    printf("%lld ", t[i]);
  puts("");
}

int main()
{
  scanf("%d%I64d%d%d%d", &n, &t[0], &a, &b, &c);
  t[1] = t[2] = t[3] = t[0];
  sx[0] = a; sx[1] = a+c-1; sx[2] = n;
  sy[0] = b; sy[1] = b+c-1; sy[2] = n;
  int cx = 1, cy = 1;
  if(!bestroute(cx, cy)) {
    puts("Impossible");
    return 0;
  }
  for(int i=0; i<2*n-2; ++i) {
    if(cx < n) {
      cx++;
      enter(cx, cy, -1);
      if(bestroute(cx, cy)) {
	putchar('R');
	// print();
	continue;
      }
      enter(cx, cy, 1);
      cx--;
    }
    cy++;
    enter(cx, cy, -1);
    putchar('U');
    //print();
    assert(bestroute(cx, cy));
  }
  puts("");
  return 0;
}