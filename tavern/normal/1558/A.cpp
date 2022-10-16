#include <bits/stdc++.h>

using namespace std;

#define PB push_back

vector<int> ans;

inline void calc(int A, int B, int C){ // a + b = A, c + d = B, a + c = C
  for(int a = 0; a <= A; ++a){
    int b = A - a, c = C - a, d = B - c;
    if(b >= 0 && c >= 0 && d >= 0)
      ans.PB(b + c);
  }
  return;
}

int A, B;

inline void solve(){
  scanf("%d%d", &A, &B); // a + b = A, c + d = D;
  int C = (A + B) >> 1;
  ans.clear();
  calc(A, B, C);
  calc(A, B, A + B - C);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); ++i)
    printf("%d ", ans[i]); puts("");
  return;
}

int main(){
  //freopen("A.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}