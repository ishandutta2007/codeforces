#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int mem[128];
int erased[128];

int main()
{
  int T, m, id = 1;
  int i, j, k;
  cin >> T >> m;
  for(i=0; i<m; ++i) mem[i] = 0;
  for(int I=0; I<T; ++I) {
    char op[64];
    cin >> op;
    if(op[0] == 'a') {
      int n, fr = 0;
      cin >> n;
      for(i=0; i<m; ++i) {
        if(mem[i] == 0) fr++;
        else fr = 0;
        if(fr >= n) break;
      }
      if(i < m) {
        for(j=i-n+1; j<=i; ++j)
          mem[j] = id;
        printf("%d\n", id);
        id++;
      } else puts("NULL");
    } else if(op[0] == 'e') {
      int n, del = 0;
      long long in;
      cin >> in;
      if(in < id)
        {n = in;
          if(n!=0)
      for(i=0; i<m; ++i)
        if(mem[i] == n){
          mem[i] = 0; del++;}}
      if(del==0) puts("ILLEGAL_ERASE_ARGUMENT");
    } else {
      for(i=1; i<m; ++i)
        for(j=i; j>=1 && mem[j-1] == 0; --j)
          swap(mem[j-1], mem[j]);
    }
  }
  return 0;
}