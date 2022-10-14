#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%i",&T);
  for(int Q=0;Q<T;Q++){
    double A;
    scanf("%lf",&A);
    bool ok=0;
    double bot=0,top=0,i=1;
    while(bot<A){
      bot=floor(180.00-(360.00/i));
      top=ceil(180.00-(360.00/i));
      if(bot==A&&top==A) ok=1;
      i++;
    }
    if(ok)printf("YES\n");
    else printf("NO\n");
  }
}