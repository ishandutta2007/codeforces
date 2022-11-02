#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> vehicle;

vehicle V[100000];
vector<pair<int, int> > kayak, catam;

int main()
{
  int n, v;
  scanf("%d%d", &n, &v);
  for(int i=0; i<n; ++i) {
    scanf("%d%d", &V[i].first, &V[i].second);
    if(V[i].first == 1) kayak.push_back(make_pair(V[i].second, i));
    else catam.push_back(make_pair(V[i].second, i));
  }
  sort(kayak.begin(), kayak.end()); reverse(kayak.begin(), kayak.end());
  sort(catam.begin(), catam.end()); reverse(catam.begin(), catam.end());
  for(int i=1; i<kayak.size(); ++i)
    kayak[i].first += kayak[i-1].first;
  for(int i=1; i<catam.size(); ++i)
    catam[i].first += catam[i-1].first;
  int sol = -1, soli = -1;
  for(int i=0; i<=catam.size() && 2*i <= v; ++i) {
    int vv = 0;
    int rem = min((int)kayak.size(), v-2*i);
    if(rem > 0) vv += kayak[rem-1].first;
    if(i > 0) vv += catam[i-1].first;
    if(vv > sol) {
      sol = vv;
      soli = i;
    }
  }
  printf("%d\n", max(0, sol));
  if(sol <= 0) return 0;
  soli = max(0, soli);
  for(int i=0; i<soli; ++i) printf("%d\n", catam[i].second+1);
  for(int i=0; i < kayak.size() && soli*2+i+1 <= v; ++i) printf("%d\n", kayak[i].second+1);
  return 0;
}