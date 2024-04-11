#include <bits/stdc++.h>
using namespace std;

string ok;

int main() {
 for (int i=0;i<=9;i++) {
  printf("%d%d%d%d\n",i,i,i,i);
  fflush(stdout);
  int a,b;
  scanf("%d%d",&a,&b);
  for (int j=0;j<a+b;j++) ok+=(char) ('0'+i);
 }
 do {
  printf("%s\n",ok.c_str());
  fflush(stdout);
  int a,b;
  scanf("%d%d",&a,&b);
  if (a==4) exit(0);
 } while (next_permutation(ok.begin(),ok.end()));

 return 0;
}