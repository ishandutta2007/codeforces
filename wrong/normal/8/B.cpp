#include<cstdio>
#include<set>

using namespace std;

int main()
{
  set<pair<int, int> > S;
  char O[128];
  scanf("%s", O);
  int x=0, y=0;
  S.insert(make_pair(x, y));
  int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
  for(int i=0; O[i]; ++i) {
    int px = x, py = y;
    if(O[i]=='L') x--;
    if(O[i]=='U') y++;
    if(O[i]=='D') y--;
    if(O[i]=='R') x++;
    if(S.find(make_pair(x, y)) != S.end()) {
      puts("BUG");
      return 0;
    }
    for(int j=0; j<4; ++j)
      if((x+dx[j] != px || y+dy[j] != py) && S.find(make_pair(x+dx[j],y+dy[j]))!=S.end())
	{puts("BUG");return 0;}
    S.insert(make_pair(x, y));
  }
  puts("OK");
  return 0;
}