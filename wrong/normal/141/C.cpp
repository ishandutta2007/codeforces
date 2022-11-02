#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

struct person {
  char name[12];
  int a, height;
};

bool operator < (const person& a, const person& b)
{
  return a.a < b.a;
}

person P[3000];

map<int, int> H;

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%s%d", P[i].name, &P[i].a);
  sort(P, P+n);
  int X = 1000000000;
  vector<int> sol;
  for(int i=0; i<n; ++i) {
    if(H.count(P[i].a) == 0) H[P[i].a] = X--;
    P[i].height = H[P[i].a];
    vector<int> tmp;
    if(sol.size() == 0) {
      if(P[i].a != 0) {
	puts("-1");
	return 0;
      }
      sol.push_back(0);
    } else {
      int pushed = 0;
      for(int j=0; j<(int)sol.size(); ++j) {
	if(sol.size() - j == P[i].a)
	  tmp.push_back(i), pushed=1;
	tmp.push_back(sol[j]);
      }
      if(P[i].a == 0) tmp.push_back(i), pushed=1;
      if(!pushed) {
	puts("-1");
	return 0;
      }
      sol = tmp;
    }
  }
  for(int i=0; i<n; ++i)
    printf("%s %d\n", P[sol[n-i-1]].name, P[sol[n-i-1]].height);
  return 0;
}