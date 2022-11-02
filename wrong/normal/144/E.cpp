#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;

struct sp {
  int id;
  int r, c;
  int a, b;
  sp(int i, int y, int x) {
    id = i;
    r = y;
    c = x;
    a = N - x;
    b = y - 1;
  }
};
bool operator<(const sp& a, const sp& b)
{
  return a.b > b.b;
}
bool cmppos(const sp& a, const sp& b)
{
  return a.c > b.c;
}

int main()
{
  vector<sp> S;
  scanf("%d%d", &N, &M);
  for(int i=0; i<M; ++i) {
    int r, c;
    scanf("%d%d", &r, &c);
    S.push_back(sp(i+1, r, c));
  }
  sort(S.begin(), S.end(), cmppos);
  priority_queue<sp> Q;
  vector<int> sol;
  int X = 0;
  for(int i=0; i<N; ++i) {
    while(X<M) {
      if(S[X].c >= N-i) Q.push(S[X]);
      else break;
      X++;
    }
    while(true) {
      if(Q.empty()) break;
      const sp s = Q.top(); Q.pop();
      if(s.a <= i && i <= s.b) {
	sol.push_back(s.id);
	break;
      }
    }
  }
  printf("%d\n", sol.size());
  sort(sol.begin(), sol.end());
  for(int i=0; i<(int)sol.size(); ++i)
    printf("%d%c", sol[i], i+1==(int)sol.size()?'\n':' ');
  return 0;
}