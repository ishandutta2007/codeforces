#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char inp[8][12];

int main()
{
  for(int i=0; i<8; ++i)
    scanf("%s", inp[i]);
  int sol = 16;
  for(int i=0; i<(1<<16); ++i) {
    char bd[8][12];
    memset(bd, 'W', sizeof(bd));
    for(int j=0; j<8; ++j) {
      if(i & (1<<j)) {
        for(int k=0; k<8; ++k)
          bd[j][k] = 'B';
      }
      if(i & (1<<(j+8))) {
        for(int k=0; k<8; ++k)
          bd[k][j] = 'B';
      }
    }
    bool ok = true;
    for(int j=0; j<8 && ok; ++j)
      for(int k=0; k<8 && ok; ++k)
        if(bd[j][k] != inp[j][k])
          ok = false;
    if(ok) sol = min(sol, __builtin_popcount(i));
  }
  printf("%d\n", sol);
  return 0;
}