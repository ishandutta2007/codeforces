#include<cstdio>
#include<algorithm>

using namespace std;

pair<int, int> h[1024];

int main()
{
  int n, t;
  scanf("%d%d", &n, &t);
  for(int i=0; i<n; ++i) {
    scanf("%d%d", &h[i].first, &h[i].second);
    h[i].first *= 2;
    h[i].second *= 2;
  }
  t *= 2;
  sort(h, h+n);
  int sol = 0;
  for(int i=0; i<n; ++i) {
    if(i == 0) sol++; // hidari
    else if(h[i-1].first+h[i-1].second/2 <= h[i].first-h[i].second/2-t) sol++;
    if(i == n-1) sol++; // migi
    else if(h[i+1].first-h[i+1].second/2 >= h[i].first+h[i].second/2+t) sol++;
  }
  for(int i=0; i<n-1; ++i) {
    if(h[i+1].first-h[i+1].second/2 - (h[i].first+h[i].second/2) == t) sol--; // pittari
  }
  printf("%d\n", sol);
  return 0;
}