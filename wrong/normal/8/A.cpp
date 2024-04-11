#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
  string C, a, b;
  cin >> C >> a >> b;
  bool F = false, B = false;
  int ai, bi;

  ai = C.find(a);
  bi = C.rfind(b);
  //printf("%d %d\n", ai, bi);
  if(ai != C.npos && bi != C.npos) {
    if(ai+a.length() <= bi) F = true;
  }

  reverse(C.begin(), C.end());
  ai = C.find(a);
  bi = C.rfind(b);
  if(ai != C.npos && bi != C.npos) {
    if(ai+a.length() <= bi) B = true;
  }

  if(F && B) puts("both");
  else if(F) puts("forward");
  else if(B) puts("backward");
  else puts("fantasy");
  return 0;
}