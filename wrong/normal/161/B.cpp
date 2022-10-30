#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct item {
  int c, t, id;
  bool used;
  item(int a, int b, int c)
    : c(a), t(b), id(c), used(false) { }
};
bool operator < (const item& a, const item& b)
{
  return a.c < b.c;
}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  vector<item> I;
  for(int i=0; i<n; ++i) {
    int c, t;
    scanf("%d%d", &c, &t);
    I.push_back(item(c, t, i+1));
  }
  sort(I.begin(), I.end());

  long long ans = 0, p5 = 0;
  vector<vector<int> > sol;
  for(int i=n-1; k>1 && i>=0; --i) {
    if(I[i].t == 1) {
      ans += I[i].c / 2;
      if(I[i].c % 2 == 1) {
	if(p5 == 1) ans++, p5 = 0;
	else p5 = 1;
      }
      sol.push_back(vector<int>());
      sol.back().push_back(I[i].id);
      I[i].used = true;
      k--;
    }
  }

  for(int i=0; k>1 && i<n; ++i) {
    if(!I[i].used) {
      ans += I[i].c;
      sol.push_back(vector<int>());
      sol.back().push_back(I[i].id);
      I[i].used = true;
      k--;
    }
  }

  int mm = 1000000009, discount = 0;
  sol.push_back(vector<int>());
  for(int i=0; i<n; ++i) {
    if(!I[i].used) {
      if(I[i].t == 1) discount = 1;
      if(mm > I[i].c) mm = I[i].c;
      ans += I[i].c;
      sol.back().push_back(I[i].id);
    }
  }
  if(discount) {
    ans -= mm / 2;
    if(mm % 2 == 1) {
      if(p5 == 1) p5 = 0;
      else ans--, p5 = 1;
    }
  }

  printf("%I64d.%d\n", ans, p5 ? 5 : 0);
  for(int i=0; i<(int)sol.size(); ++i) {
    printf("%d ", sol[i].size());
    for(int j=0; j<(int)sol[i].size(); ++j)
      printf("%d%c", sol[i][j], j+1==(int)sol[i].size() ? '\n' : ' ');
  }
  return 0;
}