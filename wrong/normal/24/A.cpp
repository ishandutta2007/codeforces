#include<cstdio>
#include<vector>

using namespace std;

vector<int> to[100], co[100];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--; b--;
    to[a].push_back(b); co[a].push_back(0);
    to[b].push_back(a); co[b].push_back(c);
  }
  int sol = 0, pos = to[0][0], prv = 0;
  for(int i=1; i<n; ++i) {
    for(int j=0; j<2; ++j) {
      if(to[pos][j] != prv) {
	sol += co[pos][j];
	prv = pos;
	pos = to[pos][j];
      }
    }
  }
  int sol2 = 0;
  pos = to[0][1]; prv = 0;
  for(int i=1; i<n; ++i) {
    for(int j=0; j<2; ++j) {
      if(to[pos][j] != prv) {
	sol2 += co[pos][j];
	prv = pos;
	pos = to[pos][j];
      }
    }
  }
  printf("%d\n", sol<sol2?sol:sol2);
  return 0;
}